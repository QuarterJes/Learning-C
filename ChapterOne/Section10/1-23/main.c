#include <stdio.h>
#define MAXFILE 1000

void removeComments();
char getProgram();

main() {
  removeComments();

}


void removeComments() {
  int c;
  int s = 0;
  while((c = getchar()) != EOF) {

    printf("%c", c);
  }
}
