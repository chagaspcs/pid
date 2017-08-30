class dsf_Temporizador
{
  private:
  	int tempo=0;
  	int segundo=0;
  	int aux=0;

  public:
    bool decrementador();
    void resetar();
    void incrementador();
    int consulta();
};