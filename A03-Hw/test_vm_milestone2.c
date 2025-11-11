#include "common/computer.h"
#include <vector>
#include <stdio.h>
#include <string.h>

void RunTest(const char* program, 
  const std::vector<int>& addresses, 
  const std::vector<int>& values)
{
  printf("Testing %s...\n", program);

  hack::Computer computer;
  computer.load(program);
  computer.run();

  uchar binvalue[16];
  char message[1024];
  for (int i = 0; i < addresses.size(); i++)
  {
    computer.read_ram(addresses[i], binvalue);
    int value = bin2dec(binvalue, true);
    snprintf(message, 1024, "Check: RAM[%d] = %d? (Got %d)", 
      addresses[i], values[i], value); 
    check(value == values[i], message);
  }
}

int main()
{
  RunTest("vm/SimpleIfLt.hack", {0, 256, 257, 5, 6}, {256, 3, 2, 3, 0});
  RunTest("vm/SimpleIfGt.hack", {0, 256, 257, 5, 6}, {256, 4, 1, 0, 4});
  RunTest("vm/SimpleWhile.hack", {0, 256, 257, 5, 6}, {256, -1, 3, 3, 0});
  RunTest("vm/AddFn/AddFn.hack", {0, 256, 261, 262}, {257, 15, 15, 8});
}
