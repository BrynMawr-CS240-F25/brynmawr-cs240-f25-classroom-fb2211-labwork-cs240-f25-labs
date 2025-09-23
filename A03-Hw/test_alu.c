#include "alu.h"
#include "utils.h"

int main()
{
  uchar a[16];
  uchar b[16];
  uchar out[16];
  uchar zr, ng;

  hack::Zero16(a);
  hack::Zero16(b);

  hack::ALU(a, b, 1, 0, 1, 0, 1, 0, out, &zr, &ng);
  check(bin2dec(out) == 0, "2a. zero");
  check(zr == 1, "2b. isZero = true");
  check(ng == 0, "2c. isNeg = false");
  
  dec2bin(4, a);
  dec2bin(3, b);
  hack::ALU(a, b, 0, 0, 0, 0, 1, 0, out, &zr, &ng);
  check(bin2dec(out) == 7, "3a. a+b = 7");
  check(zr == 0, "3b. isZero = false");
  check(ng == 0, "3c. isNeg = false");
}
