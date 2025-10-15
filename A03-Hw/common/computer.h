#ifndef _computer_H_
#define _computer_H_

#include "cpu.h"
#include "gates.h"
#include "ram.h"
#include "fast_ram.h"

namespace hack
{
  class Computer
  {
    public:
      Computer() : m_reset(0) {}
      void load(const char* filename);
      void write_ram(unsigned int address, uchar data[16]);
      void read_ram(unsigned int address, uchar data[16]);
      void read_rom(unsigned int address, uchar data[16]);
      void list(int start_instruction, int num_instructions);
      void set_breakpoint(unsigned int bp);
      void clear_breakpoint();
      bool finished();
      void run();
      void reset();
      void tick();

      void inspect(const char* name);
      int program_counter_value();

   friend void test_computer();

   private:
      unsigned int m_breakpoint;
      uchar m_reset;
      CPU m_cpu;
#ifdef FAST_RAM
      Fast_RAM32K m_ram; 
      Fast_RAM32K m_rom; 
#else
      RAM32K m_ram;
      RAM32K m_rom;
#endif
      unsigned int m_num_instructions;
  };

  void test_computer();

}

#endif

