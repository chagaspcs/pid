class dsf_DivFreq
{
  private:
  	mkl_GPIOPort botao;
  	mkl_GPIOPort led;
  	int bit=0;

  public:
    //int consulta ();
    bool onoff(mkl_GPIOPort botao_in, mkl_GPIOPort led_in); 

};