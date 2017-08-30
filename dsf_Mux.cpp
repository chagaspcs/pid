#include "dsf_Mux.h"

bool dsf_Mux::contador()
{
  if (aux == 0){
    aux = 100;
    return true;
  }
  else{
    aux = aux - 1;
    return false
  }
}
