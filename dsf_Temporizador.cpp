#include "dsf_Temporizador.h"

int dsf_Temporizador::decrementador()
{
  if (tempo == 0){
    return -1;
  }
  else
  {
    tempo = tempo - 1;
    return tempo;
  }
}

void dsf_Temporizador::resetar()
{
  tempo = 0;
}

void dsf_Temporizador::incrementador()
{
  if (tempo >= 90){
    tempo = 0;
  }
  else{
    aux = tempo%10;
    tempo = tempo - aux;
    tempo = tempo + 10;
    aux = 0;
  }
}

int dsf_Temporizador::consulta()
{
  return  tempo;
}
