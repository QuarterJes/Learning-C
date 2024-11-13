#include <stdio.h>

#define MAXLINE 99

int getline(char to[], int lim);

int main(int argc, char **argv) {
  char s[MAXLINE];
  int result = getline(s, MAXLINE);
  printf("%d\n", result);
  return 0;
}

int getline(char s[], int lim) {
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
