#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char **argv) {
  /* for char */
  printf("========== char ==========\n");
  printf("Value for char: %d\n", CHAR_BIT);

  /* for short int */
  printf("\n========== short int ==========\n");
  printf("Minimum value for a short int: %d\n", SHRT_MIN);
  printf("Maximum value for a short int: %d\n", SHRT_MAX);
  printf("Minimum value for an unsigned short int: 0\n");
  printf("Maximum value for an unsigned short int: %d\n", USHRT_MAX);

  /* for int */
  printf("\n========== int ==========\n");
  printf("Minimum value for int: %d\n", INT_MIN);
  printf("Maximum value for int: %d\n", INT_MAX);
  printf("Minimum value for an unsigned int: 0\n");
  printf("Maximum value for an unsigned int: %u\n", UINT_MAX);


  /* for long int */
  printf("\n========== long int ==========\n");
  printf("Minmum value for long int: %ld\n", LONG_MIN);
  printf("Maximum value for long int: %ld\n", LONG_MAX);
  printf("Minimum value for unsigned long int: 0");
  printf("Maximum value for unsigned long int: %lu\n", ULONG_MAX);

  /*for short float
  TODO
  */
}
