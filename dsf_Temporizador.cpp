#include "dsf_Temporizador.h"

	bool decrementador();
    void resetar();
    void incrementador();

bool dsf_Temporizador::decrementador()
{
  if (aux == 0){
    return true;
  }
  else{
    aux = aux - 1;
    return false
  }
}

void dsf_Temporizador::resetar()
{
  aux == 0;
}

void dsf_Temporizador::incrementador()
{
  if (aux > 90){
    aux = 0;
  }
  else{
    aux = aux + 10;
  }
}
