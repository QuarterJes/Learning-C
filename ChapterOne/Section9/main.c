#include <stdio.h>
#define MAXLENGTH 1000
#define THRESHOLD 5

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void append(char to[], char from[], int a, int b);

main() {
  // exercise 1-16
  char longest_line[MAXLENGTH];
  char line[MAXLENGTH];
  int longest, current;

  longest = 0;
  // while ((current = get_line(line, MAXLENGTH)) > 0) {
  //   if (current > longest) { 
  //    longest = current;
  //    copy(longest_line, line);
  //   }
  // }
  
  // printf("\n%s \n", longest_line);

  // exercise 1-17
  char above_threshold[MAXLENGTH]; 
  int total_length, total_words;
  total_length = 0;
  
  while ((current = get_line(line, MAXLENGTH)) > 0) {
    if (current > THRESHOLD) {
      ++total_words;
      total_length += current;
      if (total_length - current == 0)
        copy(above_threshold, line);
      else
        append(above_threshold, line, (total_length - current + (total_words - 2)), (total_length + (total_words - 2)));
    }
  }

  printf("\n%s \n", above_threshold);
}
  
  
int get_line(char line[], int maxline) {
  int i, c;

  i = 0;
  while (i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i; 
}

void copy(char to[], char from[]) {
  int i;
  
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

void append(char to[], char from[], int start, int end) {
  int i, j;

  j = 0;
  to[start] = '\n';
  for (i = start + 1; i <= end; ++i) {
    to[i] = from[j];
    ++j;
  }

  to[end+1] = '\0';
}
