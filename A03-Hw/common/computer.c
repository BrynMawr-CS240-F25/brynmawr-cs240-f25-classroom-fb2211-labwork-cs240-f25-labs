#include "computer.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

namespace hack
{
  void Computer::load(const char* filename)
  {
  }

  void Computer::tick()
  {
  }

  void Computer::write_ram(unsigned int address, uchar data[16])
  {
  }

  void Computer::read_ram(unsigned int address, uchar data[16])
  {
  }

  void Computer::read_rom(unsigned int address, uchar data[16])
  {
  }

  bool Computer::finished()
  {
    return false;
  }

  void Computer::run()
  {
  }

  void Computer::list(int start, int num)
  {
  }

  void Computer::inspect(const char* token)
  {
  }

  void Computer::clear_breakpoint()
  {
  }

  void Computer::set_breakpoint(unsigned int instruction_num)
  {
  }
  
  void Computer::reset()
  {
  }
  
  int Computer::program_counter_value()
  {
    return 0;
  }

  void test_computer()
  {
    hack::Computer computer;
    computer.load("hack/M[3]=M[4]+1.hack");
    
    uchar instruction[16];
    for (int i = 0; i < computer.m_num_instructions; i++)
    {
      computer.read_rom(i, instruction);
      printf("%02d: ", i); print(instruction);
    }
    printf("\n");

    check(bin2dec(computer.m_cpu.PC.out) == 0, "\nPC 0 to start");
    computer.tick(); // A=4
    check(bin2dec(computer.m_cpu.PC.out) == 1, "\nPC 1");
    check(bin2dec(computer.m_cpu.A.out) == 4, "A = 4");
    check(bin2dec(computer.m_cpu.addressM) == 4, "cpu.addressM = 4");
    check(computer.m_cpu.writeM == 0, "cpu.writeM = 0");

    computer.tick(); // D=M
    check(bin2dec(computer.m_cpu.PC.out) == 2, "\nPC 2");
    check(bin2dec(computer.m_cpu.A.out) == 4, "A = 4");
    check(bin2dec(computer.m_cpu.D.out) == 0, "D = M[4] = 0");
    check(bin2dec(computer.m_cpu.inM) == 0, "cpu.inM = 0");
    check(bin2dec(computer.m_cpu.outM) == 0, "cpu.outM = 0");
    check(bin2dec(computer.m_cpu.addressM) == 4, "cpu.addressM = 4");
    check(computer.m_cpu.writeM == 0, "cpu.writeM = 0");
    
    computer.tick(); //D=D+1
    check(bin2dec(computer.m_cpu.PC.out) == 3, "\nPC 3");
    check(bin2dec(computer.m_cpu.A.out) == 4, "A = 4");
    check(bin2dec(computer.m_cpu.D.out) == 1, "D = 1");
    check(bin2dec(computer.m_cpu.addressM) == 4, "cpu.addressM = 4");
    check(computer.m_cpu.writeM == 0, "cpu.writeM = 0");

    computer.tick(); // @3
    check(bin2dec(computer.m_cpu.PC.out) == 4, "\nPC 4");
    check(bin2dec(computer.m_cpu.A.out) == 3, "A = 3");
    check(bin2dec(computer.m_cpu.D.out) == 1, "D = 1");
    check(bin2dec(computer.m_cpu.addressM) == 3, "cpu.addressM = 3");
    check(computer.m_cpu.writeM == 0, "cpu.writeM = 0");

    computer.tick(); // M=D
    check(bin2dec(computer.m_cpu.PC.out) == 5, "\nPC 5");
    check(bin2dec(computer.m_cpu.A.out) == 3, "A = 3");
    check(bin2dec(computer.m_cpu.D.out) == 1, "D = 1");
    check(bin2dec(computer.m_cpu.addressM) == 3, "cpu.addressM = 3");
    check(bin2dec(computer.m_ram.in) == 1, "ram.in = 1");
    check(bin2dec(computer.m_ram.address) == 3, "ram.address = 3");
    check(bin2dec(computer.m_ram.out) == 1, "ram.out = 1");
    check(computer.m_cpu.writeM == 1, "cpu.writeM = 1");
    
    computer.tick(); //A=6
    check(bin2dec(computer.m_cpu.PC.out) == 6, "\nPC 6");
    check(bin2dec(computer.m_cpu.A.out) == 6, "A = 6");
    check(computer.m_cpu.writeM == 0, "cpu.writeM = 0");

    computer.tick(); //0;JMP
    check(bin2dec(computer.m_cpu.PC.out) == 6, "\nPC 6");
    check(bin2dec(computer.m_cpu.A.out) == 6, "A = 6");
    check(computer.m_cpu.writeM == 0, "cpu.writeM = 0");
  }
}
