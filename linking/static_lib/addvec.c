#include <stdio.h>
int addvec_called = 0;


void addvec(int* x, int* y, int* z, int n)
{
  int i = 0;
  addvec_called++;

  printf("addvec called\n");
  for (i = 0; i < n; ++i)
    {
      z[i] = x[i] + y[i];
    }

}
  
