#include <stdio.h>

#define MAXLINE 99

int getline(char to[], int lim);

int main(int argc, char **argv) {
  char s[MAXLINE]; // String to be stored
  int result = getline(s, MAXLINE); // Number of characters in string
  printf("Number of characters: %d\n", result);
  printf("Actual string: %s\n", s);
  return 0;
}

int getline(char s[], int lim) {
  // Exercise was to use no && and || operators
  int valid = 1;
  int i = 0;
  while (valid) {
    int c = getchar();
    if (c == EOF)
      valid = 0;
    else if (c == '\n')
      valid = 0;
    else {
      s[i] = c;
      ++i;
    }
  }
  s[i] = '\0';
  return i;
}
