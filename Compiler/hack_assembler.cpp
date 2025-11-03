#include <stdio.h>
#include <vector>
#include <string.h>
#include "common/filereader.h"
#include "common/instruction.h"
#include "common/assembler.h"
#include "common/utils.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("usage: %s <file.asm>\n", argv[0]);
    return 0;
  }

  hack::FileReader reader;
  if (!reader.open(argv[1]))
  {
    return 0;
  }

  std::vector<hack::Instruction> instructions;
  while (reader.hasMoreLines())
  {
    hack::Instruction instruction;
    strncpy(instruction.cmd, reader.line(), MAX_CMD);
    instructions.push_back(instruction);
    reader.advance();
  }

  // modify extension from .asm to .hack
  char outfilename[MAX_CMD];
  change_extension(argv[1], ".hack", outfilename, MAX_CMD); 

  hack::Assembler assembler;
  assembler.translate(instructions);
  assembler.write(outfilename, instructions);
  return 0;
}
