/*!
 * @copyright   © 2017 UFAM - Universidade Federal do Amazonas.
 *
 * @brief       Programa exemplo de uso da classe dsf_PIT_ocp.
 *
 * @file        main.cpp
 * @version     1.0
 * @date        6 Julho 2017
 *
 * @section     HARDWARES & SOFTWARES
 *              +board        FRDM-KL25Z da NXP.
 *              +processor    MKL25Z128VLK4 - ARM Cortex-M0+.
 *              +peripheral   PIT - Periodic Interrupt Timer.
 *              +compiler     Kinetis® Design Studio IDE
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012
 *              +revisions    Versão (data): Descrição breve.
 *                             ++ 1.0 (6 Julho 2017): Versão inicial.
 *
 * @section     AUTHORS & DEVELOPERS
 *              +institution  Universidade Federal do Amazonas
 *              +courses      Engenharia da Computação / Engenharia Elétrica
 *              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
 *              +student      Versão inicial:
 *                             ++ Jose Luis da Silva <joseluis70123@gmail.com>
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
#include "MKL25Z4.h"
#include "mkl_PIT.h"
#include <gpio.h>
#include <stdint.h>
#include <mkl_PITDelay.h>
#include <mkl_PITPeriodicInterrupt.h>


/*!
 *  Definição dos objetos PIT e chamadas dos métodos constutores.
 */
 mkl_PITDelay pit(PIT_Ch0);


/*!
 *  Definição do objeto led a ser usado.
 */
Gpio led;


/*!
 *  Configuração dos objetos PIT e Led
 */
void setup() {
  led.init();
  pit.enablePeripheralModule();
  pit.setPeriod(0x1406F3F);
}

/*!
 *  Configuração dos objetos PIT e Led
 */
int main(void) {
  setup();
  pit.resetCounter();
  pit.enableTimer();
  while(1){
	  pit.startDelay();
	  led.invertCurrentState();
  }

  return 0;
}
