#include "common/filereader.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
  hack::FileReader parser;
  parser.open("asm/SetA.asm");
  while (parser.hasMoreLines())
  {
    printf("%s\n", parser.line());
    parser.advance();
  }
  return 0;
}
