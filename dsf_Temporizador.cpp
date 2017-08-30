#include "dsf_Temporizador.h"

bool dsf_Temporizador::decrementador()
{
  if (tempo == 0){
    return true;
  }
  else{
      if(segundo == 60){
        tempo = tempo - 1;
      }
      else{
        segundo = segundo + 1;
      }
    return false
  }
}

void dsf_Temporizador::resetar()
{
  tempo == 0;
}

void dsf_Temporizador::incrementador()
{
  if (tempo > 90){
    tempo = 0;
  }
  else{
    aux = tempo%10;
    tempo = tempo - aux;
    tempo = tempo + 10;
    aux = 0;
  }
}

void dsf_Temporizador::consulta()
{
  return  tempo;
}
