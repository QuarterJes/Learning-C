#include <stdio.h>
#include <stdbool.h>

void deleteComments(char *fileName);

// This is a very basic solution. I will update so it complies with strings.
int main(int argc, char **argv) {
  if (argc != 2)
    printf("Error\nFormat should be ./main filename\n");
  else
    deleteComments(argv[1]);


  return 0;
}


void deleteComments(char *fileName) {
  FILE *inputFile;
  inputFile = fopen(fileName, "r");
  if (inputFile == NULL) {
    printf("File does not exist!\n");
  }
  else {
    int slash = 0;
    bool newLine = true;
    FILE *outputFile;
    outputFile = fopen("output.txt", "w");
    int c;
    while ((c = getc(inputFile)) != EOF) {
      if (c == '/' && getc(inputFile) == '/') {
        newLine = false;
      }
      else if (c == '\n') {
        putc(c, outputFile);
          newLine = true;
      }
      else if (newLine == true) {
        putc(c, outputFile);
      } 
    }
  }
}

