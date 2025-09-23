#include "gates.h"
#include "utils.h"

int main()
{
  uchar values[8];
  
  hack::Zero(&values[0]);
  check(values[0] == 0, "1: zero");

  hack::Ones(&values[0]);
  check(values[0] == 1, "2: one");

  hack::Dmux(1, 0, &values[0], &values[1]);
  check(values[0] == 1, "3: dmux test a");
  check(values[1] == 0, "4: dmux test b");
  
  hack::Mux(0, 1, 0, &values[0]);
  check(values[0] == 0, "5: mux1 test a");
}
