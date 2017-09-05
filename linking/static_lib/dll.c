#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int x[2] = {1,2};
int y[2] = {3,4};

int z[2];

int main()
{

  void* pHandle;
  void  (*pfn_Addvec)(int*, int*, int*, int);
  char* pError;

  // Dynamically load the shared library containing addvec()
  pHandle = dlopen("./libvector.so", RTLD_LAZY);
  
  if (!pHandle)
    {
      fprintf(stderr, "%s\n", dlerror());
      exit(1);
    }

  //Get a pointer to the addvec() function we just loaded
  pfn_Addvec = dlsym(pHandle, "addvec");
  if ((pError = dlerror()) != NULL)
    {
      fprintf(stderr, "%s\n", pError);
      exit(1);
    }

  // Now we can call addvec() just like any other function
  pfn_Addvec(x,y,z,2);
  printf("z = [%d, %d]\n", z[0],z[1]);

  // Unload the shared library
  if (dlclose(pHandle) < 0)
    {
      fprintf(stderr, "%s\n", dlerror());
      exit(1);
    }

  return 0;

}
