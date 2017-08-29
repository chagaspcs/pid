#include "dsf_OnOff.h"

bool dsf_OnOff::onoff(mkl_GPIOPort botao_in, mkl_GPIOPort led_in)
{
  botao = botao_in;
  led = led_in;

  if(botao.readBit()==0)
  {
    bit = !readBit;
    led.writeBit(bit);
  return true;
  }
  else
    return false;
}