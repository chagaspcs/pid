#include "dsf_DivFreq.h"

bool dsf_DivFreq::contador()
{
  if (aux == 0){
    aux = 300;
    return true;
  }
  else{
    aux = aux - 1;
    return false;
  }
}
