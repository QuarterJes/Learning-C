#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main() {
  // exercise 1-16
  char c;
  char longest_line[MAXLINE];
  char line[MAXLINE];
  int longest, current, i;

  while ((current = get_line(line, MAXLINE)) > 0) {
    if (current > longest) { 
     longest = current;
     copy(longest_line, line);
    }
  }
  
  if (longest > 0)
    printf("\n%s", longest_line);
  printf("\n%d\n", longest);
}

int get_line(char line[], int maxline) {
  int i;
  char c;

  for (i = 0; i < maxline - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    line[i] = c;
  }
  line[i] = '\0';
  return i; 
}

void copy(char to[], char from[]) {
  int i;
  
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
  ++i;
  to[i] = '\0';
}
