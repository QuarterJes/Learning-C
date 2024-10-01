#include <stdio.h>

main() {
  int fahr;

  for (fahr = 0; fahr <= 300; fahr += 20)
    printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
 
  // exercise 1-5
  printf("Fahrenheit  Celsius\n");
  for (fahr = 300; fahr >= 0; fahr -= 20) {
    printf("%5d %12.2f\n", fahr, (5.0/9.0)*(fahr-32));
  }
}
