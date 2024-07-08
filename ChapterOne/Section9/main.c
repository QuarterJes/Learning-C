#include <stdio.h>
#define MAXLENGTH 1000
#define THRESHOLD 6

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void append(char to[], char from[], int a, int b);
int remove_blanks(char to[], int maxline);
void reverse_string(char line[], char new_line[], int lenght);

main() {
  // exercise 1-16
  // char longest_line[MAXLENGTH];
  // char line[MAXLENGTH];
  // int longest, current;

  // longest = 0;
  // while ((current = get_line(line, MAXLENGTH)) > 0) {
  //   if (current > longest) { 
  //    longest = current;
  //    copy(longest_line, line);
  //   }
  // }
  
  // printf("\n%s \n", longest_line);

  // exercise 1-17
  //  char above_threshold[MAXLENGTH]; 
  //  int total_characters, total_lines;
  //  total_characters = total_lines = 0;
  //  
  //  while ((current = get_line(line, MAXLENGTH)) > 0) {
  //    if (current-1 > THRESHOLD) {
  //      ++total_lines;
  //      total_characters += current;
  //      if (total_lines == 1)
  //        copy(above_threshold, line);
  //      else
  //        append(above_threshold, line, total_characters - current, total_characters);
  //    }
  //  }
 
  //  if (total_lines > 0)
  //    printf("\n%s \n", above_threshold);
  //
  //
 
  // exercise 1-18

  // char current_line[MAXLENGTH], output[MAXLENGTH];
  // int line_characters, total_characters;  
  // line_characters = total_characters = 0;
 
  // while ((line_characters = remove_blanks(current_line, MAXLENGTH)) > 0) {
  //   if (line_characters > 1) {
  //     total_characters += line_characters;
  //     if (total_characters - line_characters == 0)
  //       copy(output, current_line);
  //     else
  //       append(output, current_line, total_characters - line_characters, total_characters);
  //   }
  // }

  // if (total_characters > 0)
  //   printf("%s \n", output);

  // exercise 1-19
  char line[MAXLENGTH], output[MAXLENGTH], reversed_line[MAXLENGTH];
  int length, total_characters;
  total_characters = length = 0;

  while ((length = get_line(line, MAXLENGTH)) > 0) {
    if (length > 1) {
      total_characters += length;
      reverse_string(line, reversed_line, length-1);
      if (total_characters - length == 0)
        copy(output, reversed_line);
      else
        append(output, reversed_line, total_characters - length, total_characters);
    }
  }

  if (total_characters > 0)
    printf("%s \n", output);
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

int remove_blanks(char line[], int maxline) {
  int i, j, spaces, tabs;
  char c;

  spaces = tabs = 0;
  i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (c == ' ') {
      ++spaces;
      if (spaces < 2) {
        line[i] = c;
        ++i;
      }
    }
    else if (c == '\t') {
      ++tabs;
      if (tabs < 2) {
        line[i] = c;
        ++i;
      }
    }
    else {
      spaces = tabs = 0;
      line[i] = c;
      ++i;
    }
  }
  if (c == '\n')
    ++i;

  return i;
}

void reverse_string(char line[], char new_line[], int length) {
  int i;

  new_line[length] = '\0';
  for (i = 0; i < length; ++i)
    new_line[i] = line[length-i-1];
}
