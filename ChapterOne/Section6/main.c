#include <stdio.h>

main() {
  // exercise 1-13
  // horizontal version
  //  char c;
  //  int letters[5];
  //  int current_word, i, j;

  //  c = getchar();

  //  for (i = 0; i < 5; ++i)
  //    letters[i] = 0;

  //  current_word = 0;

  //  while (c != EOF) {
  //    if (c == ' ' || c == '\t' || c == '\n') {
  //      ++current_word;
  //    }
  //    else {
  //      if (current_word < 5) {
  //        letters[current_word] += 1; 
  //      } 
  //    }
  //    c = getchar();
  //  }

  //  printf("Letters in each word\n");
  //  for (i = 0; i < 5; ++i) {
  //    printf("Letter %d: ", i+1);
  //    for (j = 1; j <= letters[i]; j++)
  //      if (j % 5 == 0)
  //        printf("*");
  //      else
  //        printf("-");
  //    printf("\n");
  //  }
  // printf("\n");

  // vertical version
  // char c;
  // int i, j, current_word, largest;
  // int letters[5];

  // // initialsie all elements to 0
  // for (i = 0; i < 5; ++i)
  //   letters[i] = 0;

  // current_word = 0;

  // // get length of each word
  // c = getchar();
  // while (c != EOF) {
  //   if (c == ' ' || c == '\t' || c == '\n') {
  //     ++current_word;
  //   }
  //   else {
  //     if (current_word < 5) {
  //       letters[current_word] += 1; 
  //     } 
  //   }
  //   c = getchar();
  // }
  // 
  // // find largest word length
  // largest = -1;
  // for (i = 0; i < 5; ++i) {
  //   if (largest < letters[i])
  //     largest = letters[i];
  // }

  // // print vertical histogram
  // int k;
  // printf("\n\n");
  // int offset;
  // for (i = largest; i > 0; --i) {
  //   for (j = 0; j < 5; ++j) {
  //     if (letters[j] - i >= 0) {
  //       if (i % 5 == 0)
  //         printf("*");
  //       else
  //         printf("|");
  //     }
  //     else {
  //       printf(" ");
  //     }
  //         printf(" ");
  //     }
  //   printf("\n");
  // }

  // printf("\n1 2 3 4 5\n");

  // exercise 1-14
  char c;
  int letters, numbers, other;
  c = getchar();

  letters = numbers = other = 0;
  while (c != EOF) {
    if (c >= '0' && c <= '9')
      ++numbers;
    else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
      ++letters;
    else {
      ++other;
    }

  c = getchar(); 
  }

  printf("\nletters: %d\nnumbers: %d\nother: %d\n", letters, numbers, other);

 
  }

