//#include "dsf_GPIO_ocp.h"
#include "mkl_GPIOPort.h"

class dsf_OnOff
{
  private:
  	mkl_GPIOPort botao;
  	mkl_GPIOPort led;
  	int bit=0;

  public:
    //int consulta ();
    bool onoff(mkl_GPIOPort botao_in, mkl_GPIOPort led_in); 

};