#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int power(int m, int n);
float convert(double f);

main() {
  int i;

  for (i = 0; i < 10; ++i) {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  }

  // exercise 1-15
  printf("Fahrenheit   Celsius");
  int fahr;
  for (fahr = LOWER; fahr < UPPER; fahr += STEP) {
    printf("%6d %13.2f\n", fahr, convert(fahr));
  }
}

int power(int base, int n) {
  int i, p;
  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base; 
  return p;
}

float convert(double fahrenheit) {
  return (5.0/9.0) * (fahrenheit-32);
}
