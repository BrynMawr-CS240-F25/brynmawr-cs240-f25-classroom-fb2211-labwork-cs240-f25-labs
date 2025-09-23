#include <stdlib.h>
#include <stdio.h>

void check(bool expr, const char* message) 
{
  if (!expr)
  {
    printf("%s: FAILED\n", message);
  }
  else
  {
    printf("%s: PASSED\n", message);
  }
}


void check(unsigned char v[16], unsigned char u[16], const char* msg) 
{
  bool expr = true;
  for (int i = 0; i < 16 && expr; i++)
  {
    expr = (v[i] == u[i]);
  }

  if (!expr) 
  {
    printf("%s: FAILED\n", msg);
  }
  else
  {
    printf("%s: PASSED\n", msg);
  }
}

void dec2bin(int input, unsigned char out[16])                                    
{                                                                               
}                               

int bin2dec(unsigned char binary[16], bool isSigned)
{
  return 0;
}

void print(unsigned char binary[16])
{
  for (int i = 0; i < 16; i++)
  {
    if (i > 0 && i % 4 == 0) printf(" ");
    printf("%d", binary[i]);
  }
  printf("\n");
}
