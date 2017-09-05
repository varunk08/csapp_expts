int multvec_called = 0;


void multvec(int* x, int* y, int* z, int n)
{

  int i=0;
  multvec_called++;
  for(i=0; i< n; ++i)
    {
      z[i]=x[i]*y[i];
    }

}
