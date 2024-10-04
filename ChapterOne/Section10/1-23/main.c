#include <stdio.h>
#include <stdbool.h>

void get_string(FILE *file, char *str);
void strip_comments(char *input_str, char *output_str);

// This is a very basic solution. I will update so it complies with strings.
int main(int argc, char **argv) {
  if (argc != 2)
    printf("Error\nFormat should be ./main filename\n");
  else {
    FILE *input_file = fopen(argv[1], "r"); 
    if (input_file == NULL) {
      printf("File does not exist!\n");
    } else {
      char input_str[999];
      char stripped_str[999];
      get_string(input_file, input_str);
      strip_comments(input_str, stripped_str);
      printf("%s", stripped_str);
    }
  }

  return 0;
}

void get_string(FILE *file, char *str) {
  int c, i;
  i = 0;
  while ((c = fgetc(file)) != EOF) {
    str[i] = c;
    ++i;
  }
}

void strip_comments(char *input_str, char *output_str) {
  int speech = 0; 
  int quotes = 0;
  bool single_comment = false;
  bool multi_comment = false;
  int i, j;
  j = 0;
  for (i = 0; input_str[i] != EOF; ++i) {
    if (input_str[i] == '\'') {
      ++quotes;
    } else if (input_str[i] == '\"') {
      ++speech;
    }
    if (input_str[i] != '/' && !single_comment && !multi_comment) {
      output_str[j] = input_str[i];
      ++j;
    } else if (input_str[i] == '/' && (speech % 2 == 1 || quotes % 2 == 1) && !single_comment && !multi_comment) {
      output_str[j] = input_str[i];
      ++j;
    } else if (input_str[i] == '/') {
      ++i;
      if (input_str[i] == '*') {
        multi_comment = true;    
      } else if (input_str[i] == '/') {
        single_comment = true;
      }
    } else if (input_str[i] == '\n') {
      if (multi_comment) {
        output_str[j] = '\n';
        ++j;
      } else if (single_comment) {
        single_comment = false;
        output_str[j] = '\n';
        ++j;
      } else {
        output_str[j] = input_str[i];
        ++j;
      }
    } else if (input_str[i] == '*') {
      ++i;
      if (input_str[i] == '/') {
        multi_comment = false;  
      } 
    }
  }
}
