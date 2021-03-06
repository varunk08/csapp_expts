#ifdef RUNTIME
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void* malloc(size_t size)
{

  void* (*pMalloc)(size_t size);
  char* pError;


  pMalloc = dlsym(RTLD_NEXT, "malloc");

  if((pError = dlerror()) != NULL)
    {
      fputs(pError, stderr);
      exit(1);
    }

  void* ptr = pMalloc(size);

  printf("malloc(%d): %p\n", (int)size, ptr);
  return ptr;

}

void free(void* ptr)
{
  void* (*pFree)(void*) = NULL;
  char* pError;


  pFree = dlsym(RTLD_NEXT, "free");

  if((pError = dlerror()) != NULL)
    {
      fputs(pError, stderr);
      exit(1);
    }

  pFree(ptr);
  printf("free(%p)\n",  ptr);
}

#endif
