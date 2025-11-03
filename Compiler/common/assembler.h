#ifndef _Assembler_H_
#define _Assembler_H_

#include <vector>
#include <string>
#include <unordered_map>
#include "instruction.h"
#include "utils.h"

namespace hack
{
  InstructionType cmd_type(const char* line);
  void cmd_symbol(const char* line, char* value, int size);
  void cmd_dest(const char* line, char* value, int size);
  void cmd_comp(const char* line, char* value, int size);
  void cmd_jump(const char* line, char* value, int size);
  void write_jmp_code(const char* jmp, uchar code[16]);
  void write_dest_code(const char* dest, uchar code[16]);
  void write_comp_code(const char* comp, uchar code[16]);
  void write_a(int value, uchar code[16]);

  class Assembler
  {
  public:
    Assembler();
    virtual ~Assembler();

    void translate(std::vector<Instruction>& instructions);
    bool write(const char* filename, 
      const std::vector<Instruction>& instructions) const;

  private:
    void initSymbolTable();
    std::unordered_map<std::string, int> mSymbolTable;
  };
};

#endif

