/*!
 * @copyright   � 2017 UFAM - Universidade Federal do Amazonas.
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
 *              +compiler     Kinetis� Design Studio IDE
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012
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
 *   @brief      Configura os perif�ricos GPIO e TPM.
 *
 *   Esta fun��o realiza a configura��o dos perif�ricos GPIO e TPM para
 *   o modo de sa�da e o fator da frequ�ncia de opera��o.
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
 *   Este programa realiza o teste da classe do perif�rico TPM no modo delay,
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
     * O valor em hexadecimal 0xFFFF � o maior valor de contagem poss�vel e
     * corresponde a 400 ms aproximadamente.
     */
    tpm.waitDelay(0xFFFF);
    led.writeBit(1);
    /*!
     * Aguarda 400 ms.
     * O valor em hexadecimal 0xFFFF � o maior valor de contagem poss�vel e
     * corresponde a 400 ms aproximadamente.
     */
    tpm.waitDelay(0xFFFF);
    tpm.cancelDelay();
  }
  return 0;
}
