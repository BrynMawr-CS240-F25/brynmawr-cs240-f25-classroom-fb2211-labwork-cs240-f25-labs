#include <stdio.h>
#include "common/assembler.h"

void checkstr(const char* value, const char* expected, const char* message)
{
  if (strcmp(value, expected) == 0)
  {
    printf("%s: PASSED\n", message);
  }
  else
  {
    printf("%s: FAILED (got %s, expected %s)\n", message, value, expected);
  }
}

void test_command(const char* cmd, 
  const char* dest, const char* comp, const char* jmp)
{
  char buffer[MAX_CMD];
  char message[MAX_CMD];
  
  snprintf(message, 128, "%s dest", cmd);
  hack::cmd_dest(cmd, buffer, MAX_CMD);
  checkstr(buffer, dest, message);
  
  snprintf(message, 128, "%s comp", cmd);
  hack::cmd_comp(cmd, buffer, MAX_CMD);
  checkstr(buffer, comp, message);
  
  snprintf(message, 128, "%s jump", cmd);
  hack::cmd_jump(cmd, buffer, MAX_CMD);
  checkstr(buffer, jmp, message);
}

int main(int argc, char* argv[])
{
  check(hack::cmd_type("@i") == hack::A_INSTRUCTION, "A instruction type");
  check(hack::cmd_type("(END)") == hack::L_INSTRUCTION, "L instruction type");
  check(hack::cmd_type("D;JMP") == hack::C_INSTRUCTION, "C instruction type");

  char buffer[MAX_CMD];

  hack::cmd_symbol("@i", buffer, MAX_CMD);
  checkstr(buffer, "i", "cmd_symbol");
  
  hack::cmd_symbol("(END)", buffer, MAX_CMD);
  checkstr(buffer, "END", "cmd_symbol");

  test_command("D;JMP", "", "D", "JMP");
  test_command("AD=0", "AD", "0", "");
  test_command("D=M+1", "D", "M+1", "");
  test_command("D=1;JMP", "D", "1", "JMP");

  uchar code[16];
  hack::write_dest_code("M", code);
  hack::write_comp_code("M+1", code);
  hack::write_jmp_code("", code);

  uchar incM[16] = {1,1,1, 1, 1,1,0,1,1,1, 0,0,1, 0,0,0};
  check(code, incM, "M=M+1");
  
  uchar A[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,1,1};
  hack::write_a(11, code);
  check(code, A, "@11");
  return 0;
}
