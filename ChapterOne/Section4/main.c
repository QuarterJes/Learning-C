#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

main() {
  int fahr;

  // exercise 1-5
  printf("Fahrenheit  Celsius\n");
  for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
    printf("%5d %12.2f\n", fahr, (5.0/9.0)*(fahr-32));
  }
}
