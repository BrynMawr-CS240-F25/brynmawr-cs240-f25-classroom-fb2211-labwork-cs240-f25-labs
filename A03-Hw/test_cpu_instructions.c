#include <stdio.h>
#include "cpu.h"
#include "utils.h"

void run_cpu(hack::CPU* cpu, uchar instruction[16])
{
  uchar inM[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 1,1,1,1};
  uchar A[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,0,1};
  uchar D[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 1,1,0,1};

  printf("\nExecute: "); print(instruction);
  hack::Set16(instruction, cpu->instruction);
  hack::Set16(inM, cpu->inM); 
  hack::Set16(A, cpu->A.out); 
  hack::Set16(D, cpu->D.out); 
  hack::Zero16(cpu->PC.out); 

  cpu->tick();
}

void check_cpu(hack::CPU* cpu, int outputs[6])
{
  char buff[32];
  int test = bin2dec(cpu->A.out); 
  snprintf(buff, 32, "A==%d? Value: %d", outputs[0], test);
  check(test == outputs[0], buff); 

  test = bin2dec(cpu->D.out, true); 
  snprintf(buff, 32, "D==%d? Value: %d", outputs[1], test);
  check(test == outputs[1], buff); 

  test = bin2dec(cpu->PC.out); 
  snprintf(buff, 32, "PC==%d? Value: %d", outputs[2], test);
  check(test == outputs[2], buff); 
  
  test = bin2dec(cpu->outM, true); 
  if (cpu->instruction[0] == 0)
  {
    snprintf(buff, 32, "outM undefined. Value: %d", test);
    check(true, buff); 
  }
  else
  {
    snprintf(buff, 32, "outM==%d? Value: %d", outputs[3], test);
    check(test == outputs[3], buff); 
  }

  test = bin2dec(cpu->addressM); 
  snprintf(buff, 32, "addressM==%d? Value: %d", outputs[4], test);
  check(test == outputs[4], buff); 

  snprintf(buff, 32, "writeM==%d? Value: %d", outputs[5], cpu->writeM);
  check(cpu->writeM == outputs[5], buff); 
}

int main()
{
  uchar instructions[][16] = {
    {1,1,1, 0, 1,1,1,1,1,1, 1,1,0, 0,0,0}, // A=1,D=1
    {1,1,1, 0, 1,0,1,0,1,0, 1,1,0, 0,0,0}, // A=0,D=0
    {1,1,1, 1, 1,0,1,0,1,0, 0,1,1, 0,0,0}, // M=0,D=0
    {0,1,1, 1, 1,1,1,1,1,1, 1,1,1, 1,1,1}, // A=0x7FFF
    {1,1,1, 0, 1,1,0,0,0,0, 0,1,0, 0,0,0}, // D=A

    {1,1,1, 0, 0,0,1,1,0,1, 0,0,0, 0,0,0}, // !D 
    {1,1,1, 0, 1,1,0,0,0,1, 0,0,0, 0,0,0}, // !A 
    {1,1,1, 0, 0,0,1,1,1,1, 0,0,0, 0,0,0}, // -D
    {1,1,1, 0, 1,1,0,0,1,1, 0,0,0, 0,0,0}, // -A
    {1,1,1, 0, 0,1,1,1,1,1, 0,0,0, 0,0,0}, // D+1 
    {1,1,1, 0, 1,1,0,1,1,1, 0,0,0, 0,0,0}, // A+1 
    {1,1,1, 0, 0,0,1,1,1,0, 0,0,0, 0,0,0}, // D-1 
    {1,1,1, 0, 1,1,0,0,1,0, 0,0,0, 0,0,0}, // A-1 
    {1,1,1, 0, 0,0,0,0,1,0, 0,0,0, 0,0,0}, // D+A
    {1,1,1, 0, 0,1,0,0,1,1, 0,0,0, 0,0,0}, // D-A
    {1,1,1, 0, 0,0,0,1,1,1, 0,0,0, 0,0,0}, // A-D
    {1,1,1, 0, 0,0,0,0,0,0, 0,0,0, 0,0,0}, // D&A
    {1,1,1, 0, 0,1,0,1,0,1, 0,0,0, 0,0,0}, // D|A

    {1,1,1, 0, 0,0,1,1,0,0, 0,0,1, 0,0,0}, // M[A]=D (e.g. M[9] = 9)
    {1,1,1, 1, 1,1,0,1,1,1, 0,0,1, 0,0,0}, // M[A] = M[A] + 1 
    {1,1,1, 1, 1,1,0,0,0,0, 0,1,0, 0,0,0}, // D = M[A]
    {1,1,1, 1, 0,0,0,0,1,0, 1,0,0, 0,0,0}, // A = D+M (A = 18)

    {1,1,1, 0, 0,0,1,1,0,0, 0,0,0, 0,0,1},  // D;JGT
    {1,1,1, 0, 0,0,1,1,0,0, 0,0,0, 0,1,0},  // D;JEQ
    {1,1,1, 0, 0,0,1,1,0,0, 0,0,0, 0,1,1},  // D;JGE
    {1,1,1, 0, 0,0,1,1,0,0, 0,0,0, 1,0,0},  // D;JLT
    {1,1,1, 0, 0,0,1,1,0,0, 0,0,0, 1,0,1},  // D;JNE
    {1,1,1, 0, 0,0,1,1,0,0, 0,0,0, 1,1,0},  // D;JLE
    {1,1,1, 0, 0,0,0,0,0,0, 0,0,0, 1,1,1}  // 0;JMP
  };

  // Outputs: A, D, PC, outM, addressM, writeM
  int cpu_outputs[][6] = {
    {1, 1, 1, 1, 1, 0}, // A=1,D=1
    {0, 0, 1, 0, 0, 0}, // A=0,D=0
    {9, 0, 1, 0, 9, 1}, // M=0,D=0
    {32767, 13, 1, 0, 32767, 0}, // A=0x7FFF
    {9, 9, 1, 9, 9, 0}, // D=A

    {9, 13, 1, -14, 9, 0}, // !D 
    {9, 13, 1, -10, 9, 0}, // !A 
    {9, 13, 1, -13, 9, 0}, // -D
    {9, 13, 1, -9, 9, 0}, // -A

    {9, 13, 1, 14, 9, 0}, // D+1 
    {9, 13, 1, 10, 9, 0}, // A+1 
    {9, 13, 1, 12, 9, 0}, // D-1 
    {9, 13, 1, 8, 9, 0}, // A-1 
    {9, 13, 1, 22, 9, 0}, // D+A
    {9, 13, 1, 4, 9, 0}, // D-A
    {9, 13, 1, -4, 9, 0}, // A-D
    {9, 13, 1, 9, 9, 0}, // D&A
    {9, 13, 1, 13, 9, 0}, // D|A

    {9, 13, 1, 13, 9, 1}, // M[A]=D (e.g. M[9] = 13)
    {9, 13, 1, 16, 9, 1}, // M[A] = M + 1 (e.g. M[9] = 15 + 1) 
    {9, 15, 1, 15, 9, 0}, // D = M
    {28, 13, 1, 28, 28, 0}, // A = D+M (A = 15 + 13)

    {9, 13, 9, 13, 9, 0},  // D;JGT
    {9, 13, 1, 13, 9, 0},  // D;JEQ
    {9, 13, 9, 13, 9, 0},  // D;JGE
    {9, 13, 1, 13, 9, 0},  // D;JLT
    {9, 13, 9, 13, 9, 0},  // D;JNE
    {9, 13, 1, 13, 9, 0},  // D;JLE
    {9, 13, 9, 9, 9, 0}  // 0;JMP (outM = D&A)
  };

  int num = sizeof(instructions) / sizeof(instructions[0]);

  hack::CPU cpu;
  for (int i = 0; i < num; i++)
  {
    run_cpu(&cpu, instructions[i]);
    check_cpu(&cpu, cpu_outputs[i]);
  }
  return 0;
}
