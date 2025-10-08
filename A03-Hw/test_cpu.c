#include <stdio.h>
#include "cpu.h"
#include "utils.h"

int main()
{
  uchar instruction[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,0,1};

  hack::CPU cpu;
  hack::Set16(instruction, cpu.instruction);
  print(cpu.A.out); // should be zero
  cpu.tick();
  print(cpu.A.out); // should be nine

  // todo: test other instructions
}
