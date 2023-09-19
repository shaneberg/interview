#include <stdio.h>
#include <math.h>
// You have n equal-sized blocks and you want to build a staircase with them.
// Return the number of steps you can fully build.

// 0  -> 0
// 1  -> 1
// 2  -> 1
// 3  -> 2
// 4  -> 2
// 5  -> 2
// 6  -> 3
// 7  -> 3
// 8  -> 3
// 9  -> 3
// 10 -> 4
// 11 -> 4
// 12 -> 4
// 13 -> 4
// 14 -> 4
// 15 -> 5

// #
// ##
// ###
// ####
// #####

unsigned int buildStaircase(unsigned int blocks) {
    unsigned int complete_levels = 0;

    while (blocks > complete_levels) {
        complete_levels++;
        blocks = blocks - complete_levels;
    }

    return complete_levels;
}

unsigned int buildStaircaseConstantTime(unsigned int blocks) {
    return (-1 + sqrt(1 + 8 * blocks)) / 2;
}

int main() {
    printf("%s\n", buildStaircase(0)  == 0 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(1)  == 1 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(2)  == 1 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(3)  == 2 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(4)  == 2 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(5)  == 2 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(6)  == 3 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(7)  == 3 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(8)  == 3 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(9)  == 3 ? "pass" : "FAIL");
    printf("%s\n", buildStaircase(10) == 4 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(0)  == 0 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(1)  == 1 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(2)  == 1 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(3)  == 2 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(4)  == 2 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(5)  == 2 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(6)  == 3 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(7)  == 3 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(8)  == 3 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(9)  == 3 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(10) == 4 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(11) == 4 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(12) == 4 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(13) == 4 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(14) == 4 ? "pass" : "FAIL");
    printf("%s\n", buildStaircaseConstantTime(15) == 5 ? "pass" : "FAIL");
    return 0;
}
