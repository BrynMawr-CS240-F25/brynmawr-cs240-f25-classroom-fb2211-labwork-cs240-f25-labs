#ifndef _cpu_H_
#define _cpu_H_

#include "gates.h"
#include "ram.h"

namespace hack
{
  class CPU
  {
    public:
      CPU() : reset(0), writeM(0) { Zero16(inM); }
      void tick();

      // inputs
      uchar inM[16];
      uchar instruction[16];
      uchar reset; 

      // outputs
      uchar outM[16];
      uchar writeM;
      uchar addressM[16];

      // internals with state
      Register A;
      Register D;
      Counter PC;
  };
}

#endif
