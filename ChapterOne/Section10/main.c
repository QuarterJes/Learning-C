#include <stdio.h>
#define MAXLENGTH 1000

void detab(char to[], char from[]);
void entab(char to[], char from[]);
int get_line(char line[], int maxlength);
void copy(char to[], char from[]);
void append(char to[], char from[], int start, int end);
void fold_lines(char line[]);

int tabstop; 
tabstop = 8;

main() {
  // exercise 1-20
  // i didnt really understand what the exercise was trying to get
  // me to do... i searched online and it seems that my
  // solution gives the expected outputs so hopefully it is right
  // char raw_input[MAXLENGTH], clean_input[MAXLENGTH], output[MAXLENGTH];
  // int len, total;
  // tabstop = 5;
  // total = 0;
  // while ((len = get_line(raw_input, MAXLENGTH)) > 0) {
  //   if (len > 1) {
  //     total += len;
  //     detab(clean_input, raw_input);
  //     if (total - len == 0)
  //       copy(output, clean_input);
  //     else
  //       append(output, clean_input, total - len, total);
  //   }
  // }

  // printf("\n%s \n", output);

  // exercise 1-21
  // char input[MAXLENGTH], output[MAXLENGTH];
  // int len;
  // while ((len = get_line(input, MAXLENGTH)) > 0) {
  //   entab(output, input);  
  // }

  // printf("%s \n", output); 
  
}


void detab(char to[], char from[]) {
  int i, j;
  extern tabstop;
  j = 0;
  for (i = 0; from[i] != '\0'; ++i) {
    if (j % tabstop != 0 && from[i] == '\t') {
      while (j % tabstop != 0) {
        to[j] = ' ';
        ++j;
      }
    }
    else {
      to[j] = from[i];
      ++j;
    }
  }
  to[j] = '\0';
}

void entab(char to[], char from[]) { // this outputs an easier-to-read format. 
                                     // for the real deal, replace '.' with ' ' and '-' with '\t'
  int spaces, i, j;
  spaces = 0;
  extern tabstop;
  i = 0;
  for (j = 0; from[j] != '\n'; ++j) {
    to[i] = from[j];
    if (from[j] == ' ' || from[j] == '\t') {
      to[i] = '.';
      ++spaces;
    }
    else {
      spaces = 0;
    }

    if ((j+1) % tabstop == 0 && spaces > 0) {
      --spaces;
      i -= spaces;
      to[i] = '-';
      spaces = 0;
    }
    ++i;
  } 
  to[i] = '\0';
}


int get_line(char line[], int maxlength) {
  int i;
  char c;
  i = 0; 
  while (i < maxlength - 1 && (c = getchar()) != EOF) {
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

}

void append(char to[], char from[], int start, int end) {
  int i, j;
  j = 0;
  
  to[start-1] = '\n'; 
  for (i = start; i < end-1; ++i) {
    to[i] = from[j];
    ++j;
  }
}

