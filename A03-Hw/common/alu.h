#ifndef _adders_H_
#define _adders_H_

#include "gates.h"

namespace hack
{
  void HalfAdder(uchar a, uchar b, uchar* carry, uchar* sum);
  void FullAdder(uchar a, uchar b, uchar c, uchar* carry, uchar* sum);
  void Add16(uchar a[16], uchar b[16], uchar out[16]);
  void Inc16(uchar a[16], uchar out[16]);
  void ALU(uchar x[16], uchar y[16], 
    uchar zx, uchar nx, uchar zy, uchar ny, uchar f, uchar no, 
    uchar out[16], uchar* zr, uchar* ng);
}

#endif