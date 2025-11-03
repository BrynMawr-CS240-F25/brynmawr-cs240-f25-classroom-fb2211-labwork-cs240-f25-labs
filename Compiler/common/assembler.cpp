#include "assembler.h"
#include "utils.h"
#include <assert.h>

namespace hack
{
  //---------------------------------------
  // Parsing and translation functions
  //---------------------------------------
  InstructionType cmd_type(const char* line)
  {
    return A_INSTRUCTION;
  }

  void cmd_symbol(const char* line, char* value, int size)
  {
  }

  void cmd_dest(const char* line, char* value, int size)
  {
  }

  void cmd_comp(const char* line, char* value, int size)
  {
  }

  void cmd_jump(const char* line, char* value, int size)
  {
  }

  void write_jmp_code(const char* jmp, uchar code[16])
  {
  }

  void write_dest_code(const char* dest, uchar code[16])
  {
  }

  void write_comp_code(const char* comp, uchar code[16])
  {
  }

  void write_a(int value, uchar code[16])
  {
  }

  //---------------------------------------
  // Assembler 
  //---------------------------------------

  Assembler::Assembler()
  {
  }

  Assembler::~Assembler()
  {
  }

  bool Assembler::write(const char* filename, 
    const std::vector<Instruction>& instructions) const
  {
    return false;
  }
    
  void Assembler::initSymbolTable()
  {
  }

  void Assembler::translate(std::vector<Instruction>& instructions)
  {
  }
};

