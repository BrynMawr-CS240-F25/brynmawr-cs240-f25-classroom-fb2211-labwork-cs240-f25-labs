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
  
  // Set defaults for LCL and ARG
  uchar binvalue[16];
  dec2bin(300, binvalue); computer.write_ram(1, binvalue);
  dec2bin(400, binvalue); computer.write_ram(2, binvalue);
  
  // Run program
  computer.run();

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
  // Getting started
  RunTest("vm/Bootstrap.hack", {0, 256}, {256, 0});
  RunTest("vm/SimpleConstant.hack", {0, 256}, {257, 111});

  // arithmetic tests
  RunTest("vm/SimpleAdd.hack", {0, 256}, {257, 15});
  RunTest("vm/SimpleSub.hack", {0, 256}, {257, -1});
  RunTest("vm/SimpleNeg.hack", {0, 257}, {258, -8});
  RunTest("vm/SimpleAnd.hack", {0, 256}, {257, 0});
  RunTest("vm/SimpleOr.hack",  {0, 256}, {257, 15});
  RunTest("vm/SimpleNot.hack", {0, 257}, {258, -9});
  RunTest("vm/SimpleEq.hack", {0, 256, 257}, {258, -1, 0});
  RunTest("vm/SimpleLt.hack", {0, 256, 257, 258}, {259, -1, 0, 0});
  RunTest("vm/SimpleGt.hack", {0, 256, 257, 258}, {259, 0, -1, 0});

  // memory tests
  RunTest("vm/SimpleStatic.hack", {0, 256, 16, 17, 19, 24}, {256, 111, 111, 111, 0, 0});
  RunTest("vm/SimpleTemp.hack", {0, 256, 5, 8, 11}, {256, 111, 0, 111, 111});
  RunTest("vm/SimplePointer.hack", {0, 3, 4, 256}, {256, 2048, 2058, 2058});
  RunTest("vm/SimpleThis.hack", {0, 3, 4, 256, 2048, 2050}, {256, 2048, 0, 8, 8, 8});
  RunTest("vm/SimpleThat.hack", {0, 3, 4, 256, 2048, 2050}, {256, 0, 2048, 8, 8, 8});
  RunTest("vm/SimpleLocal.hack", {0, 1, 256, 303, 306}, {256, 300, 111, 111, 111});
  RunTest("vm/SimpleArgument.hack", {0, 2, 256, 403, 406}, {256, 400, 111, 111, 111});
}
