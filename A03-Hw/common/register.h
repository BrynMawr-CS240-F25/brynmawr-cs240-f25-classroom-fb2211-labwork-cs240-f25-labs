#ifndef _register_H_
#define _register_H_

#include "gates.h"
#include "alu.h"

namespace hack
{
  class Bit // one-bit data flip-flop
  {
    public: 
      Bit();
      void tick();
      uchar in;
      uchar load;
      uchar out;
  };

  class Register 
  {
    public: 
      Register(); 
      virtual void tick(); 
      uchar in[16];
      uchar out[16];
      uchar load;
  };
  
  class Counter : public Register
  {
    public: 
      Counter();
      virtual void tick();
      uchar inc;
      uchar reset;
  };
}
#endif 