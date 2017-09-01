/*!
 * @copyright   © 2017 UFAM - Universidade Federal do Amazonas.
 *
 * @brief       AR CONDICIONADO DIGITAL
 *
 *
 * @version     1.0
 * @date        28 Agosto 2017
 *
 * @section     HARDWARES & SOFTWARES
 *              +board        FRDM-KL25Z da NXP.
 *              +processor    MKL25Z128VLK4 - ARM Cortex-M0+
 *              +Peripheral   TPM, GPIO e Led RGB.
 *              +compiler     Kinetis® Design Studio IDE
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012
 *
 * @section     AUTHORS & DEVELOPERS
 *              +institution  Universidade Federal do Amazonas
 *              +courses      Engenharia da Computação
 *              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
 *              +student      Versão inicial:
 *                             ++ Patrick Chagas dos Santos <patrick.chagas@gmail.com>
 *
 * @section     LICENSE
 *
 *              GNU General Public License (GNU GPL).
 *
 *              Este programa é um software livre; Você pode redistribuí-lo
 *              e/ou modificá-lo de acordo com os termos do "GNU General Public
 *              License" como publicado pela Free Software Foundation; Seja a
 *              versão 3 da licença, ou qualquer versão posterior.
 *
 *              Este programa é distribuído na esperança de que seja útil,
 *              mas SEM QUALQUER GARANTIA; Sem a garantia implícita de
 *              COMERCIALIZAÇÃO OU USO PARA UM DETERMINADO PROPÓSITO.
 *              Veja o site da "GNU General Public License" para mais detalhes.
 *
 * @htmlonly    http://www.gnu.org/copyleft/gpl.html
 */


#include "mkl_TPM Delay/mkl_TPMDelay.h"
#include "mkl_PIT Delay/mkl_PIT.h"
#include "mkl_PIT Delay/mkl_PITDelay.h"
#include "mkl_PITPeriodicInterrupt/mkl_PITPeriodicInterrupt.h"
#include "mkl_GPIO Port/mkl_GPIOPort.h"
#include "dsf_SerialDisplays.h"
#include "dsf_DivFreq.h"
#include <stdint.h>
#include "dsf_OnOff.h"
#include "dsf_Temporizador.h"
#include "dsf_Mux.h"



// SETUP dos pinos em uso no projeto

mkl_GPIOPort blueLed(gpio_PTD1);
mkl_GPIOPort greenLed(gpio_PTB19);

mkl_GPIOPort onoffKey(gpio_PTB8);
mkl_GPIOPort sleepKey(gpio_PTB9);
mkl_GPIOPort resetKey(gpio_PTB10);
mkl_GPIOPort decKey(gpio_PTB11);



mkl_PITInterruptInterrupt pit(PIT_Ch0);
mkl_TPMDelay tpm(tpm_TPM0);


dsf_SerialDisplays disp(gpio_PTC7, gpio_PTC0, gpio_PTC3);

dsf_DivFreq divisor;
dsf_Temporizador temporizador;
dsf_OnOff standby;
dsf_Mux seletor;

int bit=0;

  int setupPIT()
  {
	pit.enablePeripheralModule();
	pit.setPeriod(35000);
   	
   	pit.resetCounter();
    pit.enableTimer();
    pit.enableInterruptRequests();
}


void setupGPIO()
{
 
  //Configura o pino para o modo saída.
  
  blueLed.setPortMode(gpio_output);
  greenLed.setPortMode(gpio_output);
  
  //Configura o pino para o modo entrada com resistor de pull up.
  
  onoffKey.setPortMode(gpio_input);
  onoffKey.setPullResistor(gpio_pullUpResistor);

  sleepKey.setPortMode(gpio_input);
  sleepKey.setPullResistor(gpio_pullUpResistor);

  decKey.setPortMode(gpio_input);
  decKey.setPullResistor(gpio_pullUpResistor);

  resetKey.setPortMode(gpio_input);
  resetKey.setPullResistor(gpio_pullUpResistor);

  greenLed.writeBit(0);
  blueLed.writeBit(1);
}

void setupTPM()
{
  tpm.setFrequency(tpm_div128);
}

extern "C"
{
  void PIT_IRQHandler(void)
  {

    if(divisor.contador())
    {
    	if(temporizador.decrementador()==0)
    	{
    		disp.clearDisplays();
    		disp.hideZerosLeft();
    		disp.updateDisplays();
    		greenLed.writeBit(0);
    		bit=0;
    	}
    }

    pit.clearInterruptFlag();
  }
}


int main() {
 
  //variaveis
 //  int bit=0;

  //setup do GPIO
  setupGPIO();

  //setup do PIT
  setupPIT();
  
  //setup do TPM
  setupTPM();
  tpm.startDelay(20);

  disp.clearDisplays();
 // disp.hideZerosLeft();

  while (true)
  {
	  disp.updateDisplays();

	  if (!onoffKey.readBit()&&tpm.timeoutDelay())
	  {
		  //tpm.waitDelay(0x6000);	//Debounce
		  bit = standby.onoff();
		  greenLed.writeBit(bit);
		  disp.clearDisplays();
		  temporizador.resetar();
		  tpm.startDelay(25000);
	  }

	  if(bit)
	  {
		  disp.updateDisplays();
		  disp.writeWord(temporizador.consulta());

		  if (!resetKey.readBit()&&tpm.timeoutDelay())
		  {
			  temporizador.resetar();
			  tpm.startDelay(25000);
		  }

		  if (!sleepKey.readBit()&&tpm.timeoutDelay())
		  {
			  temporizador.incrementador();
			  tpm.startDelay(25000);
		  }

	  }

	  if (temporizador.consulta() )
	  {
		  blueLed.writeBit(0);
	  }
	  else
	  {
		  blueLed.writeBit(1);
	  }

	  disp.hideZerosLeft();
  }
  return 0;
}

