#include <stdio.h>

void squeeze(char *s1, char *s);

int main (int argc, char **argv) {
  char s1[] = "Jesang";
  char s2[] = "ng";
  squeeze(s1, s2);
  printf("%s\n", s1);
  return 0;
}

void squeeze(char *s1, char *s2) {
  int i, j, k;
  for (i = 0; s2[i] != '\0'; ++i) {
    for (j = k = 0; s1[j] != '\0'; ++j) {
      if (s1[j] != s2[i]) {
        s1[k++] = s1[j]; 
      }
    }
    s1[k] = '\0';
  }
}
