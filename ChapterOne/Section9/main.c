#include <stdio.h>
#define MAXLENGTH 1000
#define THRESHOLD 6

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void append(char to[], char from[], int a, int b);

main() {
  // exercise 1-16
  char longest_line[MAXLENGTH];
  char line[MAXLENGTH];
  int longest, current;

  // longest = 0;
  // while ((current = get_line(line, MAXLENGTH)) > 0) {
  //   if (current > longest) { 
  //    longest = current;
  //    copy(longest_line, line);
  //   }
  // }
  
  // printf("\n%s \n", longest_line);

  // exercise 1-17
  char above_threshold[MAXLENGTH]; 
  int total_characters, total_lines;
  total_characters = total_lines = 0;
  
  while ((current = get_line(line, MAXLENGTH)) > 0) {
    if (current-1 > THRESHOLD) {
      ++total_lines;
      total_characters += current;
      if (total_lines == 1)
        copy(above_threshold, line);
      else
        append(above_threshold, line, total_characters - current, total_characters);
    }
  }

  if (total_lines > 0)
    printf("\n%s \n", above_threshold);

  }
  
  
int get_line(char line[], int maxline) {
  int i, c;

  i = 0;
  while (i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
    line[i] = c;
    ++i;
  }
  if (c == '\n')
    ++i;

  line[i] = '\0';
  return i; 
}

void copy(char to[], char from[]) {
  int i;
  
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;

  to[i] = '\0';
}

void append(char to[], char from[], int start, int end) {
  int i, j;

  j = 0;
  to[start-1] = '\n';
  for (i = start; i < end - 1; ++i) {
    to[i] = from[j];
    ++j;
  }

  to[end-1] = '\0';
}
