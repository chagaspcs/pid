#ifndef SOURCES_LIB_ONOFF_ONOFF_H_
#define SOURCES_LIB_ONOFF_ONOFF_H_

#include "mkl_GPIOPort/mkl_GPIOPort.h"

class Onoff{

  public:
    Onoff(mkl_GPIOPort *pin, mkl_GPIOPort *led);
    void acendeLed();
    void apagaLed();
  private:
    mkl_GPIOPort *_button;
    mkl_GPIOPort *_led;

};

#endif /* SOURCES_LIB_ONOFF_ONOFF_H_ */
