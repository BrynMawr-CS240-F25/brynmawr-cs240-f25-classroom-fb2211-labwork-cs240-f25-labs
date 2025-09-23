#ifndef _RAM_H_
#define _RAM_H_

#include "register.h"
#include "gates.h"

namespace hack
{
  template <class T, int k>
  class RAM 
  {
    public: 
      RAM() : load(0) { Zero16(in); Zero16(out); }
      void tick()
      {
      }
      
      uchar in[16];
      uchar out[16];
      T M[8];
      uchar address[16];
      uchar load;
  };

  typedef RAM<Register,3> RAM8;
  typedef RAM<RAM8,6> RAM64;
  typedef RAM<RAM64,9> RAM512;
  typedef RAM<RAM512,12> RAM4K;
  typedef RAM<RAM4K,15> RAM32K;
}

#endif
