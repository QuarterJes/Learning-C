#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);

int main (int argc, char **argv) {
  int a = setbits(0, 1, 2, 6);
  printf("%d\n",a);
  return 0;
}

int setbits(unsigned x, int p, int n, unsigned y) {
  int a, b;
  unsigned mask = ~(~0 << n);
  a = (mask & y) << p;
  b = (mask << n) & x;
  x = a | b;

  return x;
}
