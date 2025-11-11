#ifndef _vmcode_h_
#define _vmcode_h_
#define MAX_CMD 128

namespace hack
{
  enum VMType
  {
    VM_ARITHMETIC,
    VM_PUSH,
    VM_POP,
    VM_LABEL,
    VM_GOTO,
    VM_IF,
    VM_FUNCTION,
    VM_RETURN,
    VM_CALL
  };

  struct VMCommand
  {
    VMType type;
    char cmd[MAX_CMD];
    char arg1[MAX_CMD];
    char arg2[MAX_CMD];
  };
};

#endif
