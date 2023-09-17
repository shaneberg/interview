#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void printChars(char c, unsigned int n) {
    const unsigned int size = sizeof(char) * (n + 1); // +1 char for '\0' terminator

    char* str = malloc(size);
    if (str) {
        memset(str, c, size - 1 * sizeof(char));
        str[size - 1] = '\0';
        printf("%s", str);
        free(str);
    }
}

void printTree(unsigned int n) {

    printf("====== %u ======\n", n);
    for (int i = 0; i < n; i++) {
        const unsigned int spaces = n - i - 1;
        printChars(' ', spaces);

        const unsigned int marks = ((i+1) * 2) - 1;
        printChars('X', marks);

        printf("\n");
    }

}

int main() {
    printTree(0);
    printTree(1);
    printTree(2);
    printTree(3);
    printTree(5);
    printTree(7);
    printTree(10);
    return 0;
}



