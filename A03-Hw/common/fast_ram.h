#include "gates.h"
#include "utils.h"
#include <assert.h>
#include <stdio.h>

namespace hack 
{
  // Non-simulated memory which is fast enough for interactive applications
  class Fast_RAM32K
  {
    public: 
      Fast_RAM32K() : load(0) 
      { 
        Zero16(in); 
        Zero16(out);
        memset(M, 0, sizeof(char) * 0x6000 * 16); 
      }
      void tick()
      {
        unsigned int idx = bin2dec(address);
        assert(idx < 0x20000);

        Mux16(M[idx], in, load, out);
        Mux16(out, in, load, M[idx]);
        load = 0;
      }

      uchar load;
      uchar in[16];
      uchar out[16];
      uchar address[16];
      uchar M[0x20000][16];
  };
}