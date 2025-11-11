#include "common/vmtranslator.h"
#include "common/filereader.h"
#include "common/assembler.h"
#include <vector>

void testCommandParse(const char* line)
{
  hack::VMCommand cmd;
  hack::vm_parse(line, &cmd);
  printf("%s -> cmd: %d arg1: %s arg2: %s\n", line, cmd.type, cmd.arg1, cmd.arg2);
}

int main(int argc, char* argv[])
{
  const char* line1 = "push argument 1";
  const char* line2 = "label L2";
  const char* line3 = "sub";
  const char* line4 = "if-goto end";
  const char* line5 = "function print1 3";
  testCommandParse(line1);
  testCommandParse(line2);
  testCommandParse(line3);
  testCommandParse(line4);
  testCommandParse(line5);

  return 0;
}