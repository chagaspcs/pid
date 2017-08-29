/*!
 * @copyright   � 2017 UFAM - Universidade Federal do Amazonas.
 *
 * @brief       Exemplo de uso do GPIO da MKL25Z.
 *
 * @example     main.cpp
 * @version     1.0
 * @date        26 Julho 2017
 *
 * @section     HARDWARES & SOFTWARES
 *              +board        FRDM-KL25Z da NXP.
 *              +processor    MKL25Z128VLK4 - ARM Cortex-M0+
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
 *                             ++ Hamilton Nascimento <hdan_neto@hotmail.com>
 *
 * @section     LICENSE
 *
 *              GNU General Public License (GNU GPL)
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

#include "mkl_GPIOPort.h"

mkl_GPIOPort blueLed(gpio_PTD1);
mkl_GPIOPort key(gpio_PTA1);

/*!
 *   @fn         setup
 *
 *   @brief      Realiza a configura��o do perif�rico para a entrada e sa�da.
 *
 *   Este procedimento realiza a configura��o do pino PTA1 do GPIO para o modo
 *   entrada e a configura��o do pino PTD1 para o modo sa�da (RGB)
 *
 *   @details    O led RGB � do tipo anodo comum.
 */
void setup() {
  /*!
   * Configura o pino para o modo sa�da.
   */
  blueLed.setPortMode(gpio_output);
  /*!
   * Configura o pino para o modo entrada com resistor de pull up.
   */
  key.setPortMode(gpio_input);
  key.setPullResistor(gpio_pullUpResistor);
}

/*!
 *   @fn     main
 *
 *   @brief    Acende um led conforme a situa��o de uma chave.
 *
 *   Este programa realiza o teste da classe do perif�rico GPIO, onde
 *   duas portas s�o configuradas, uma como entrada e a outra como
 *   sa�da. O valor lido na entrada � escrito na sa�da.
 *
 *   @details  A porta configurada como entrada possui um resistor de pull-up
 *             interno, sendo necess�rio a liga��o da chave ao terra.
 *
 *   @return  sempre retorna o valor 0.
 */
int main() {
  int bit;

  setup();
  while (true) {
    bit = key.readBit();
    blueLed.writeBit(!bit);
  }

  return 0;
}
