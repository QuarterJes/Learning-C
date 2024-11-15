#include <float.h>
#include <limits.h>
#include <stdio.h>

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
  printf("Minimum value for an unsigned int: \n");
  printf("Maximum value for an unsigned int: %u\n", UINT_MAX);

  /* for long int */
  printf("\n========== long int ==========\n");
  printf("Minmum value for long int: %ld\n", LONG_MIN);
  printf("Maximum value for long int: %ld\n", LONG_MAX);
  printf("Minimum value for unsigned long int: 0\n");
  printf("Maximum value for unsigned long int: %lu\n", ULONG_MAX);

  /* for floats */
  printf("\n========== float ==========\n");
  printf("The smallest possible positive value for a float is: %.10e\n",
         FLT_MIN);
  printf("The largest possible positive value for a float is: %.10e\n",
         FLT_MAX);
  printf("The smallest possible negative value for a float is: %.10e\n",
         FLT_MIN * -1);
  printf("The largest possible negative value for a float is: %.10e\n",
         FLT_MAX * -1);

  /* for doubles */
  printf("\n========== double ==========\n");
  printf("The smallest possible positive value for a double is: %.10e\n",
         DBL_MIN);
  printf("The largest possible positive value for a double is: %.10e\n",
         DBL_MAX);
  printf("The smallest possible negative value for a double is: %.10e\n",
         DBL_MIN * -1);
  printf("The largest possible negative value for a double is: %.10e\n",
         DBL_MAX * -1);

  /* for long double */
  printf("\n========== long double ===========\n");
  printf("The smallest possible positive value for a long double is: %.10e\n",
         LDBL_MIN);
  printf("The largest possible positive value for a long double is: %.10e\n",
         LDBL_MAX);
  printf("The smallest possible negative value for a long double is: %.10e\n",
         LDBL_MIN * -1);
  printf("The largest possible negative value for a long double is: %.10e\n",
         LDBL_MAX * -1);
}
