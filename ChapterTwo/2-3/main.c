#include <stdio.h>

#define MAXLENGTH 20

void stoh(char *to, char *from); /* Strip 0x or 0X from hexadecimal string */
int is_valid_hex(char *s); /* Checks if string is a valid hexadecimal number */
int htoi(char *s, int digits); /* Converts the hexadecimal to denary */
int dtoh(int base, int exp); /* Given a base and exponent (in this program base will only be 16) will return base^exp */

int main(int argc, char **argv) {
  if (argc == 2) {
    char s[MAXLENGTH];
    if (argv[1][0] == '0' && (argv[1][1] == 'x' || argv[1][1] == 'X')) { /* For 0x and 0X cases */
      stoh(s, argv[1]);
      int valid_hex = is_valid_hex(s);
      printf("%s\n", s);
      if (valid_hex > 0) {
        int denary_value = htoi(s, valid_hex);
        printf("The number %s to denary is: %d\n", argv[1], denary_value);
      } else {
        printf("Invalid hexadecimal number\n");
      }
    } else {
      int valid_hex = is_valid_hex(argv[1]);
      if (valid_hex > 0) {
        int denary_value = htoi(argv[1], valid_hex);
        printf("The number %s to denary is: %d\n", argv[1], denary_value);
      } else {
        printf("Invalid hexadecimal number\n");
      }
    }
  } else {
    printf("Please give a hexadecimal number as an argument.\n");
  }  

  return 0;
}

void stoh(char *to, char *from) {
  int i;
  int j = 0;
  for (i = 2; from[i] != EOF && from[i] != '\0'; ++i) {
    to[j] = from[i];
    ++j;
  }
  to[j] = '\0';
}

int htoi(char *s, int digits) {
  int i;
  int total = 0;
  for (i = digits - 1; i >= 0; --i) {
    if (s[i] >= 97 && s[i] <= 102) {
      total += (s[i] - 87) * dtoh(16, digits-i-1);
    } else if (s[i] >= 65 && s[i] <= 70) {
      total += (s[i] - 55) * dtoh(16, digits-i-1);
    } else {
      total += (s[i] - 48) * dtoh(16, digits-i-1);
    }
  }
  return total;
}

int is_valid_hex(char *s) {
  /* Returns 0 if not valid, else returns number of digits if valid */
  int i;
  for (i = 0; s[i] != EOF && s[i] != '\0'; ++i) {
    if (s[i] > 57 || s[i] < 48) {
      if (s[i] > 70 || s[i] < 65) {
        if (s[i] > 102 || s[i] < 97) {
          return 0;
        }
      }
    }
  }
  return i;
}

int dtoh(int base, int power) {
  int total = 1;
  if (power == 0) {
    return 1;
  } else {
    int i;
    for (i = 1; i <= power; ++i) {
      total *= base;
    }
  }
  return total;
}
