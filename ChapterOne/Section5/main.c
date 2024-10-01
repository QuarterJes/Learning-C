#include <stdio.h>

main() {
  int c;
  // c = getchar();
  // exercise 1-6 and 1-7
  // printf("You have entered: %c\n", c);
  // printf("Is the number you entered the value of EOF? %d\n", (c == EOF));
  // printf("The value of EOF is %c\n", EOF);

  // exercise 1-8
  int nl;
  int tabs;
  int blanks;

  nl = 0;
  tabs = 0;
  blanks = 0;
  // while ((c = getchar()) != EOF) {
  //   if (c == '\t')
  //     ++tabs;
  //   if (c == ' ')
  //      ++blanks;
  //   if (c == '\n')
  //     nl++;
  // }

  // printf("Number of lines: %d\nNumber of tabs: %d\nNumber of blanks: %d\n", nl, tabs, blanks);
  
  // exercise 1-9
  // c = getchar();
  // while (c != EOF) {
  //   if (c != ' ')
  //     putchar(c); 
  //   if (c == ' ')
  //     ++blanks;
  //   if (c != ' ')
  //     blanks = 0;
  //   if (blanks == 1) {
  //     putchar(c);
  //   }

  //   c = getchar();
  // }
  // omfg, this took me like a day to do...
  
  // exercise 1-10
  // note: the terminal/OS buffers the input, so the OS/terminal handles the backspace.
  // this means that backspaces are not registed, unless you switch to raw terminal mode
  // using stty (don't know what that is)

  // c = getchar();
  // while (c != EOF) {
  //   if (c == '\t') {
  //     printf("\\tb");
  //   }
  //   else if (c == '\b') {
  //     printf("\\b");
  //   }
  //   else if (c == '\\') {
  //     printf("\\");
  //   }
  //   else {
  //     putchar(c);
  //   }

  //   c = getchar();
  // }

  // exercise 1-11

  blanks = 0;
  c = getchar();
  while (c != EOF) {
    if (c == ' ') {
      ++blanks;
      if (blanks < 2)
        putchar('\n');
    }
    else {
      putchar(c);    
      blanks = 0;
    }
      
  
    c = getchar();
  }
  
    
}
