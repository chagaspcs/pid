/*!
 * @copyright   © 2017 UFAM - Universidade Federal do Amazonas.
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
 *                             ++ Hamilton Nascimento <hdan_neto@hotmail.com>
 *
 * @section     LICENSE
 *
 *              GNU General Public License (GNU GPL)
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

#include "mkl_GPIOPort.h"

mkl_GPIOPort blueLed(gpio_PTD1);
mkl_GPIOPort key(gpio_PTA1);

/*!
 *   @fn         setup
 *
 *   @brief      Realiza a configuração do periférico para a entrada e saída.
 *
 *   Este procedimento realiza a configuração do pino PTA1 do GPIO para o modo
 *   entrada e a configuração do pino PTD1 para o modo saída (RGB)
 *
 *   @details    O led RGB é do tipo anodo comum.
 */
void setup() {
  /*!
   * Configura o pino para o modo saída.
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
 *   @brief    Acende um led conforme a situação de uma chave.
 *
 *   Este programa realiza o teste da classe do periférico GPIO, onde
 *   duas portas são configuradas, uma como entrada e a outra como
 *   saída. O valor lido na entrada é escrito na saída.
 *
 *   @details  A porta configurada como entrada possui um resistor de pull-up
 *             interno, sendo necessário a ligação da chave ao terra.
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
