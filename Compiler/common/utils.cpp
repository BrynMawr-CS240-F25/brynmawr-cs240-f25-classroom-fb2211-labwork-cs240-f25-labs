#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void remove_whitespace(char* src, int maxsize)
{
  char* d = src;
  for (int i = 0; i < maxsize && *d != '\0'; i++)
  {
    while (*d == ' ' || *d == '\t' || *d == '\n' || *d == '\r') 
    {
      ++d;
    }
    *src++ = *d++;
  }
  *src = '\0';
}

void dec2bin(int input, unsigned char out[16])
{
}                               

int bin2dec(unsigned char binary[16], bool isSigned)
{
  return 0;
}

void change_extension(const char* filename, const char* newext, char* outfilename, int maxsize)
{
}
