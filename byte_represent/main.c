#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer x, int len)
{
  int i;
  for(i=0; i<len; i++)
    {
      printf("%.2x ",x[i]);
    }
  printf("\n");
}
void show_int(int a)
{
  show_bytes((byte_pointer) &a, sizeof(int));
}
void show_float(float f)
{
  show_bytes((byte_pointer) &f, sizeof(float));
}
void show_pointer(void* x)
{
  show_bytes((byte_pointer) &x, sizeof(void*));

}

int main()
{
  int a = 42;
  float f = 42.0f;
  char c = 'a';
  int* ptr = &a;

  printf("addr: %x\n", &c);

  show_int(a);
  show_float(f);
  show_pointer(ptr);

  printf("Sizes: \n");
  printf("int: %d \nfloat: %d\npointer: %d\n",sizeof(int),sizeof(float),sizeof(void*));

  return 0;
}
