/*!
 * @copyright   � 2017 UFAM - Universidade Federal do Amazonas.
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
 *              +compiler     Kinetis� Design Studio IDE
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012
 *              +revisions    Vers�o (data): Descri��o breve.
 *                             ++ 1.0 (6 Julho 2017): Vers�o inicial.
 *
 * @section     AUTHORS & DEVELOPERS
 *              +institution  Universidade Federal do Amazonas
 *              +courses      Engenharia da Computa��o / Engenharia El�trica
 *              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
 *              +student      Vers�o inicial:
 *                             ++ Jose Luis da Silva e Silva <joseluis70123@gmail.com>
 *
 * @section     LICENSE
 *
 *              GNU General Public License (GNU GPL).
 *
 *              Este programa � um software livre; Voc� pode redistribu�-lo
 *              e/ou modific�-lo de acordo com os termos do "GNU General Public
 *              License" como publicado pela Free Software Foundation; Seja a
 *              vers�o 3 da licen�a, ou qualquer vers�o posterior.
 *
 *              Este programa � distribu�do na esperan�a de que seja �til,
 *              mas SEM QUALQUER GARANTIA; Sem a garantia impl�cita de
 *              COMERCIALIZA��O OU USO PARA UM DETERMINADO PROP�SITO.
 *              Veja o site da "GNU General Public License" para mais detalhes.
 *
 * @htmlonly    http://www.gnu.org/copyleft/gpl.html
 */

#ifndef C__USERS_DIOGO_CPPLINT_MASTER_MAIN_CPP_
#define C__USERS_DIOGO_CPPLINT_MASTER_MAIN_CPP_
#include "MKL25Z4.h"
#include "mkl_PIT.h"
#include <gpio.h>
#include <stdint.h>
#include <mkl_PITDelay.h>
#include <mkl_PITPeriodicInterrupt.h>


/*!
 *  Defini��o dos objetos PIT e chamadas dos m�todos constutores.
 */
mkl_PITInterruptInterrupt pit(PIT_Ch0);


/*!
 *  Defini��o do objeto led a ser usado.
 */
Gpio led;


/*!
 *  Configura��o dos objetos PIT e Led
 */
void setup() {
  led.init();
  pit.enablePeripheralModule();
  pit.setPeriod(0x1406F3F);
}


/*!
 *  Defini��o da rotina de interrup��o do PIT
 */
extern "C" {
  void PIT_IRQHandler(void) {
    pit.clearInterruptFlag();
    led.invertCurrentState();
  }
}

/*!
 *  Configura��o dos objetos PIT e Led
 */
int main(void) {
  setup();
  pit.resetCounter();
  pit.enableTimer();
  led.invertCurrentState();
  pit.enableInterruptRequests();
  while (1) {
    pit.waitInterruptFlag();
  }

  pit.disableInterruptRequests();

  return 0;
}

#endif  // C__USERS_DIOGO_CPPLINT_MASTER_MAIN_CPP_
