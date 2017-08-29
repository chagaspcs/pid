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

#include "mkl_TPMDelay.h"
#include "mkl_PIT.h"
#include "mkl_PITDelay.h"
#include "mkl_PITPeriodicInterrupt.h"
#include "mkl_GPIOPort.h"
#include "dsf_SerialDisplays.h"

#include <stdint.h>

#include "dsf_OnOff.h"
#include "dsf_Temporizador.h"




/*!
 *  Configuração do PIT para gerar interrupções periódicas.
 */
  int setupPIT() {
	pit.enablePeripheralModule();
	pit.setPeriod(0x4e20);
   	
   	pit.resetCounter();
    pit.enableTimer();
    pit.enableInterruptRequests();
}

/*!
 *  Rotina de Serviço de Interrupção (ISR) do PIT.
 *  Atualiza as informações dos displays
 */


// SETUP dos pinos em uso no projeto

mkl_GPIOPort blueLed(gpio_PTD1);
mkl_GPIOPort greenLed(gpio_PTB19);

mkl_GPIOPort onoffKey(gpio_PTB8);
mkl_GPIOPort sleepKey(gpio_PTB9);
mkl_GPIOPort decKey(gpio_PTB10);
mkl_GPIOPort rstKey(gpio_PTB11);

void setupGPIO() {
 
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

  rstKey.setPortMode(gpio_input);
  rstKey.setPullResistor(gpio_pullUpResistor);
}

void setupTPM() {
  tpm.setFrequency(tpm_div128);
}

  //Inicializa a classe OnOff
  dsf_OnOff standby;
  
/*! . */

/*! Objeto da classe delay. */
dsf_Delay_ocp tpm(TPM_t::dsf_TPM2);

mkl_PITInterruptInterrupt pit(PIT_Ch0);

// display
dsf_SerialDisplays disp(gpio_PTC7, gpio_PTC0, gpio_PTC3);


dsf_DivFreq divisor();

dsf_Temporizador temporizador();

void setup()
{
  tpm.setFrequency(TPMDiv_t::Div128);
}

extern "C" {
  void PIT_IRQHandler(void) {
    disp.updateDisplays();
    if(divisor.contador()){
    	temporizador.decrementador();
    }
  }
}

int main() {
 
  //variaveis
  //int bit=0;

  //setup do GPIO
  setupGPIO();

  //setup do PIT
  setupPIT();
  
  //setup do TPM
  setupTPM();

disp.clearDisplays();

  while (true){
    
    if (standy.onoff(onoffKey, greenLed))
    {
		//Debounce  - Aguarda 30 ms. 4915 ciclos
		tpm.waitDelay(0x1333);
		    //Escreve no display.
    //disp.writeWord(1234);
    }
   
    if (!resetKey.readbit())
    {
    	temporizador.resetar()
		//Debounce  - Aguarda 30 ms. 4915 ciclos
		tpm.waitDelay(0x1333);
		    //Escreve no display.
    //disp.writeWord(1234);
    }
    
    if (temporizador.incrementador())
    {
		//Debounce  - Aguarda 30 ms. 4915 ciclos
		tpm.waitDelay(0x1333);
		    //Escreve no display.
    //disp.writeWord(1234);
    }
        
  }
  return 0;
}