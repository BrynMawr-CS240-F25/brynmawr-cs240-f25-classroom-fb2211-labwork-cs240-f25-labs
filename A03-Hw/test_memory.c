#include <stdio.h>
#include "register.h"
#include "ram.h"
#include "utils.h"

void print_memory(hack::RAM8* ram)
{
  for (int i = 0; i < 8; i++)
  {
    printf("%02d: ", i); print(ram->M[i].out);
  }
  printf("\n");
}

int main()
{
  hack::Bit b;
  hack::Register A;
  hack::RAM8 ram8;
  hack::RAM64 ram64;
  uchar test[16];

  b.in = 1;
  b.load = 1;
  check(b.out == 0, "1. Bit is zero");
  b.tick(); 
  check(b.out == 1, "1. Bit is one");
  check(b.load == 0, "1. Bit load reset");
  
  // store the value 9 in A
  dec2bin(9, A.in);
  A.load = 1;
  A.tick(); // load new value
  check(A.out, A.in, "2. Register set value");
  check(A.load == 0, "2. Register load reset");

  // test ram
  dec2bin(9, ram8.in);
  // Set address to 2
  ram8.address[0] = 0;
  ram8.address[1] = 1;
  ram8.address[2] = 0;
  ram8.load = 1;
  print_memory(&ram8); // should be empty
  ram8.tick(); 
  print_memory(&ram8); // should have one value at address 8

  // test PC using example in Section 3.3 of Elements of Computing Systems
  hack::Counter pc;
  dec2bin(527, pc.in);
  dec2bin(47, pc.out);
  for (int cycle = 22; cycle <= 34; cycle++)
  {
    printf("%d %d\n", cycle, bin2dec(pc.out));
    if (cycle == 23) pc.reset = 1;
    if (cycle == 25) pc.inc = 1;
    if (cycle == 29) pc.load = 1;
    if (cycle == 33) pc.inc = 0;
    pc.tick();
  }

}
