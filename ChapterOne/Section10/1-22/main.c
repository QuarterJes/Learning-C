#include <stdio.h>
#define MAXLINE 1000

int getLine(char input[]);
void foldLine(char input[], char output[]);

int maxColumn = 4;

main () {
  char input[MAXLINE], output[MAXLINE];
  int length = 0;
  while ((length = getLine(input)) > 0) {
    foldLine(input, output);
    printf("%s \n", output);
  }

}

int getLine(char input[]) {
  int i = 0;
  int c;

  while ((c = getchar()) != EOF && c != '\n' && i < MAXLINE - 1) {
    input[i] = c;
    ++i;
  }
  
  if (c == '\n') {
    input[i] = c;
    ++i;
  }
  input[i] = '\0';
  return i;
}


void foldLine(char input[], char output[]) {
  extern maxColumn;
  int column = 1;
  int i = 0;
  int j;

  for (j = 0; input[j] != '\0';++j) {
    if (column > maxColumn) {
      column = 1;
      if (output[i-1] != ' ') {
        output[i] = '-';
        ++i;
      }
      output[i] = '\n'; // create new line
      ++i;
    }
    output[i] = input[j];
    ++i;
    ++column;
  }
  output[i] = '\0';
}

