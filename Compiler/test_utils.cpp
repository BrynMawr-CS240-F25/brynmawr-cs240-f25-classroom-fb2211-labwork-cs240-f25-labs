#include <stdio.h>
#include "common/utils.h"

int main(int argc, char* argv[])
{
  char filename[128];
  char outfilename[128];

  strncpy(filename, "happy.asm", 128);
  change_extension(filename, ".hack", outfilename, 128);
  printf("%s -> %s\n", filename, outfilename);

  strncpy(filename, "happy.asm", 128);
  change_extension(filename, ".c", outfilename, 128);
  printf("%s -> %s\n", filename, outfilename);

  strncpy(filename, "happy.golucky", 128);
  change_extension(filename, ".hack", outfilename, 128);
  printf("%s -> %s\n", filename, outfilename);

  strncpy(filename, "happy.py", 128);
  change_extension(filename, ".golucky", outfilename, 128);
  printf("%s -> %s\n", filename, outfilename);

  strncpy(filename, "happy", 128);
  change_extension(filename, ".golucky", outfilename, 128);
  printf("%s -> %s\n", filename, outfilename);

  return 0;
}
