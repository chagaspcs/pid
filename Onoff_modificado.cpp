#include <Onoff.h>


Onoff::Onoff(mkl_GPIOPort *pin, mkl_GPIOPort *led)
{
  _button = pin;
  _led = led;

}

void Onoff::acendeLed()
{
	_led->writeBit(1);
}

void Onoff::apagaLed()
{
	_led->writeBit(0);
}

