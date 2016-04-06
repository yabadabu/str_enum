# str_enum.h
C++11 preprocessor macros to generate stringify versions of c++ enums

```c

#include <cstdio>
#include "str_enum.h"

DECL_STR_ENUM(eColor, Red, 10, Green, 20, Blue, 30);

int main(int argc, char** argv)
{
  eColor r = eColor::Red;
  eColor g = eColor::Green;
  eColor b = eColor::Blue;
  eColor r2 = eColor("Red");
  eColor g2 = eColor("Green");
  eColor b2 = eColor("Blue");
  eColor kk = eColor("Brown");
  printf("R is %d -> %s\n", r.value, r.c_str());
  printf("G is %d -> %s\n", g.value, g.c_str());
  printf("B is %d -> %s\n", b.value, b.c_str());
  printf("KK is %d -> %s\n", kk.value, kk.c_str());
  printf("R2 is %d\n", r2.value);
  printf("G2 is %d\n", g2.value);
  printf("B2 is %d\n", b2.value);
}

/* Output:
R is 10 -> Red
G is 20 -> Green
B is 30 -> Blue
KK is 0 ->
R2 is 10
G2 is 20
B2 is 30
*/
