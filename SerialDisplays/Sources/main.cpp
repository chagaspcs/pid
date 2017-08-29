/*!
 * @copyright   © 2017 UFAM - Universidade Federal do Amazonas.
 *
 * @brief       Exemplo de uso da classe dsf_SerialDisplays.
 *
 * @file        main.cpp
 * @version     1.0
 * @date        2 Agosto 2017
 *
 * @section     HARDWARES & SOFTWARES
 *              +board        FRDM-KL25Z da NXP.
 *              +processor    MKL25Z128VLK4 - ARM Cortex-M0+
 *              +compiler     Kinetis® Design Studio IDE
 *              +peripherals  GPIO, PIT e Módulo 74HC595 com Display 4 Dígitos.
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012
 *              +revisions    Versão (data): Descrição breve.
 *                             ++ 0.9 (17 Julho 2017): Versão inicial.
 *                             ++ 1.0 (2 Agosto 2017): Generalização dos periféricos
 *
 * @section     AUTHORS & DEVELOPERS
 *              +institution  Universidade Federal do Amazonas
 *              +courses      Engenharia Elétrica / Engenharia da Computação.
 *              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
 *              +student      Versão inicial:
 *                             ++ Magno Aguiar de Carvalho <carvalhodemagno@gmail.com>
 *                             ++ Phillipp de Souza Gama Lavor <lavorphillipp@gmail.com>
 *                             ++ Jadir Campos Barbosa Junior <jadirjr96@gmail.com>
 *              +student      Revisões - Nome revisor <e-mail do revisor>
 *                             ++v1.0 - Jose Luis da Silva e Silva <joseluis70123@gmail.com>
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

#include <dsf_SerialDisplays.h>
#include <mkl_PIT.h>
#include <mkl_PITPeriodicInterrupt.h>
#include <mkl_GPIOPort.h>
#include <stdint.h>


/*!
 *  Métodos construtores das classes usadas.
 */
mkl_PITInterruptInterrupt pit(PIT_Ch0);
dsf_SerialDisplays disp(gpio_PTC7, gpio_PTC0,gpio_PTC3);


/*!
 *  Configuração do PIT para gerar interrupções periódicas.
 */
  int setupPIT() {
	 pit.enablePeripheralModule();
	 pit.setPeriod(0x4e20);
}


/*!
 *  Rotina de Serviço de Interrupção (ISR) do PIT.
 *  Atualiza as informações dos displays
 */
extern "C" {
  void PIT_IRQHandler(void) {
    disp.updateDisplays();
  }
}

int main() {
  /*!
   *  Configura PIT para gerar interrupções a cada 10 ms.
   */
   setupPIT();
  pit.resetCounter();
  pit.enableTimer();
  pit.enableInterruptRequests();
  /*!
   *  Escreve no display o número "2019".
   */
  disp.clearDisplays();
  disp.writeWord(2019);

  while (true) { }
  return 0;
}
