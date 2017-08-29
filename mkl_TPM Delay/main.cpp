/*!
 * @copyright   © 2017 UFAM - Universidade Federal do Amazonas.
 *
 * @brief       Exemplo de uso da classe Delay.
 *
 * @example     main.cpp
 * @version     1.0
 * @date        02 Agosto 2017
 *
 * @section     HARDWARES & SOFTWARES
 *              +board        FRDM-KL25Z da NXP.
 *              +processor    MKL25Z128VLK4 - ARM Cortex-M0+
 *              +compiler     Kinetis® Design Studio IDE
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012
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
#include "mkl_TPMDelay.h"

/*!
 * Objeto led azul.
 */
mkl_GPIOPort led(gpio_PTD1);
/*!
 * Objeto da classe delay.
 */
mkl_TPMDelay tpm(tpm_TPM0);

/*!
 *   @fn         setup
 *
 *   @brief      Configura os periféricos GPIO e TPM.
 *
 *   Esta função realiza a configuração dos periféricos GPIO e TPM para
 *   o modo de saída e o fator da frequência de operação.
 *
 */
void setup() {
  led.setPortMode(gpio_output);
  tpm.setFrequency(tpm_div128);
}

/*!
 *   @fn     main
 *
 *   @brief    Pisca o led a cada 400 ms aproximadamente.
 *
 *   Este programa realiza o teste da classe do periférico TPM no modo delay,
 *   piscando um led a cada 400 ms.
 *
 *   @return  sempre retorna o valor 0.
 */
int main() {
  setup();
  while (true) {
    led.writeBit(0);
    /*!
     * Aguarda 400 ms.
     * O valor em hexadecimal 0xFFFF é o maior valor de contagem possível e
     * corresponde a 400 ms aproximadamente.
     */
    tpm.waitDelay(0xFFFF);
    led.writeBit(1);
    /*!
     * Aguarda 400 ms.
     * O valor em hexadecimal 0xFFFF é o maior valor de contagem possível e
     * corresponde a 400 ms aproximadamente.
     */
    tpm.waitDelay(0xFFFF);
    tpm.cancelDelay();
  }
  return 0;
}
