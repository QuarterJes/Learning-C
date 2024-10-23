#include <stdio.h>
#include <stdbool.h>

void get_string(FILE *file, char *str);
void strip_comments(char *input_str, char *output_str);
void find_pairs(char opening, char ending, char *str);
void find_unmatched_string(char a, char *str);

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
      find_pairs('{', '}', stripped_str);       
      find_pairs('(', ')', stripped_str);
      find_pairs('[', ']', stripped_str);
      find_unmatched_string('\'', stripped_str);
      find_unmatched_string('"', stripped_str);
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
  str[i] = '\0';
}

void strip_comments(char *input_str, char *output_str) {
  int speech = 0; 
  int quotes = 0;
  bool comment = false;
  int i, j;
  j = 0;
  for (i = 0; input_str[i] != '\0'; ++i) {
    if (input_str[i] == '\'') {
      ++quotes;
    } else if (input_str[i] == '\"') {
      ++speech;
    }
    if (input_str[i] != '/' && !comment) {
      output_str[j] = input_str[i];
      ++j;
    } else if (input_str[i] == '/' && (speech % 2 == 1 || quotes % 2 == 1) && !comment) {
      output_str[j] = input_str[i];
      ++j;
    } else if (input_str[i] == '\n') {
      comment = false;
      output_str[j] = input_str[i];
      ++j;
    } else {
      comment = true;
    }
  }
  output_str[i] = '\0';
}

void find_pairs(char opening, char ending, char *str) {
  int openings, speech_marks, quote_marks; 
  openings = -1;
  int column, row;
  column = row = 1;
  int opening_arr[999][2]; // array for all of the opening characters
  int i,j;
  i = j = speech_marks = quote_marks = 0;
  while (str[i] != '\0') { // go through the string O(n)
    if (str[i] == '\n') { // reset column and add new row
      column = 0; 
      ++row;
    } else if (str[i] == '"') {
      ++speech_marks; 
    } else if (str[i] == '\'') {
      ++quote_marks;
    }
    if ( (speech_marks % 2 == 0) && (quote_marks % 2 == 0) ) {
      if (str[i] == opening) {
        ++openings; 
        opening_arr[j][0] = row;
        opening_arr[j][1] = column;
        ++j;
      } else if (str[i] == ending) {
        --openings; 
        if (openings < -1) {
          printf("Ending %c found but no opening at line %d column %d\n", ending, row, column);
        }   
      }
    } 
    ++i; // next char
    ++column;
  }
  if (openings >= 0) {
    int k;
    for (k = 0; k <= openings; ++k) {
      printf("Opening %c at line %d, column %d but no closing %c\n", opening, opening_arr[k][0], opening_arr[k][1], ending);
    }
  }
}

void find_unmatched_string(char a, char *str) {
  int speech_marks = 0;
  int opening_speechmarks[2];
  int column, row;
  column = row = 1;
  int i, j;
  j = 0;
  for (i = 0; str[i] != '\0'; ++i) {
    if (str[i] == '\n') {
      column = 0;
      ++row; 
    } else if (str[i] == a) {
      ++speech_marks; 
      if (speech_marks % 2 == 1) {
        opening_speechmarks[0] = row;
        opening_speechmarks[1] = column; 
      }
    } 
    ++column;
  }
  if (speech_marks % 2 == 1) {
    printf("Opening %c at line %d, column %d but no closing %c\n", a, opening_speechmarks[0], opening_speechmarks[1], a); 
  }
}
