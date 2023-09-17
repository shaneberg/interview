#include <stdio.h>

// Write a method that takes 1 integer parameter:
//
//   public static void PrintTree(int n)
//   {
//       ...
//   }
//
// It prints a “tree” into the console having N rows.
//
// N = 5 produces the following output (in the console):
//
//     X
//    XXX
//   XXXXX
//  XXXXXXX
// XXXXXXXXX
//
// N = 7 produces the following output (in the console):
//
//       X
//      XXX
//     XXXXX
//    XXXXXXX
//   XXXXXXXXX
//  XXXXXXXXXXX
// XXXXXXXXXXXXX
//

void PrintTree(unsigned int n) {

    for (int i = 0; i < n; i++) {

        const unsigned int spaces = n - i - 1;
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        const unsigned int marks = ((i+1) * 2) - 1;
        for (int j = 0; j < marks; j++) {
            printf("X");
        }
        printf("\n");
    }
}

int main() {
    printf("Hello, World!\n");
    PrintTree(5);
    return 0;
}



