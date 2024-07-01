#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* Print fahrenheit
    for fahr = 0, 20, 40, ..., 300 */
main() {
  float celsius;
  int fahr;
  fahr = LOWER;

  // exercise 1-3
  // printf("Fahrenheit   Celsius\n");
  // while (fahr <= upper) {
  //   celsius = (fahr - 32) * 5/9;
  //   printf("%5.0f %12.1f\n", fahr, celsius);
  //   fahr = fahr + step;
  // }
  //
  // printf("\n");
  // exercise 1-4
  celsius = LOWER;
  printf("Celsius    Fahrenheit\n");
  while (celsius <= UPPER) {
    fahr = (celsius * 9/5) + 32;
    printf("%4.0f %15.2d\n", celsius, fahr);
    celsius += STEP;
  }

  
}
