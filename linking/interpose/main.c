#include <stdio.h>
#include <malloc.h>

int main()

{

  void* ptr= malloc(32);
  free (ptr);

  return 0;
}
