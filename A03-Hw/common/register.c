#include "register.h"

namespace hack
{
  Bit::Bit() : load(0), out(0), in(0) {}
  void Bit::tick() 
  { 
    Mux(out, in, load, &out);
    load = 0;
  }

  Register::Register() : load(0) { Zero16(out); Zero16(in); }
  void Register::tick() 
  { 
  }

  Counter::Counter() : Register(), inc(0), reset(0) {}
  void Counter::tick() 
  { 
  }
}
