#include <stdio.h>

int any(char *s1, char *s2);

int main(int argc, char **argv) {
  char input[] = "This is a test";
  char s2[] = "e";
  int result = any(input, s2);
  printf("%d\n", result);
  return 0;
}

int any(char *s1, char *s2) {
  int i, j, k;
  for (i = 0; s2[i] != '\0'; ++i) {
    for (j = 0; s1[j] != '\0'; ++j) {
      if (s2[i] == s1[j]) {
        return j+1;
      }
    }
  }
  return -1;
}
