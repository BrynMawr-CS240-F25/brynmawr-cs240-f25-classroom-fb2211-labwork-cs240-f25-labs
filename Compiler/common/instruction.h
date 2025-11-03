#ifndef _instruction_h_
#define _instruction_h_
#define MAX_CMD 128

namespace hack
{
  enum InstructionType
  {
    A_INSTRUCTION,
    C_INSTRUCTION,
    L_INSTRUCTION
  };

  struct Instruction
  {
    InstructionType type;
    char cmd[MAX_CMD];
    unsigned char machinecode[16];
  };
};

#endif