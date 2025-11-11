#include "common/filereader.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("usage: %s <filename>\n", argv[0]);
    return 0;
  }

  hack::FileReader reader;
  if (!reader.open(argv[1], false))
  {
    printf("Cannot open file: %s\n", argv[1]);
    return 0;
  }

  while (reader.hasMoreLines())
  {
    printf("%s\n", reader.line()); 
    reader.advance();
  }

  return 0;
}