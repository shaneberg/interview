#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

char* generate_n_chars(const char character, const size_t count) {
    char* str = malloc(sizeof(character) * (count + 1));

    if (str) {
        memset(str, character, count);
        str[count] = '\0';
    }

    return str;
}

void hollow_square_pattern_for_char(const char character, const size_t size) {
    printf("== Hollow Square Pattern %zu ==\n", size);

    const char left_boundary = character;
    const char right_boundary = size > 1 ? character : '\0';
    const size_t space_count = size - MIN(2, size);

    for (size_t i = 0; i < size; i++) {
        bool is_border = (i == 0 || i == size - 1);
        char c = is_border ? character : ' ';

        char* spaces = generate_n_chars(c, space_count);
        if (spaces) {
            printf("%c%s%c\n", left_boundary, spaces, right_boundary);
            free(spaces);
        }
    }

    printf("===============================\n");
}

void hollow_square_pattern(const size_t size) {
    return hollow_square_pattern_for_char('*', size);
}

void square_pattern_for_char(const char character, const size_t size) {
    printf("== Square Pattern %zu ==\n", size);

    for (size_t i = 0; i < size; i++) {
        char* str = generate_n_chars(character, size);
        if(str) {
            printf("%s\n", str);
            free(str);
        }
    }

    printf("========================\n");
}

void square_pattern(const size_t size) {
    return square_pattern_for_char('*', size);
}

int main() {
    square_pattern(0);
    square_pattern(1);
    square_pattern(5);
    hollow_square_pattern(0);
    hollow_square_pattern(1);
    hollow_square_pattern(2);
    hollow_square_pattern(3);
    hollow_square_pattern(4);
    hollow_square_pattern(5);
    return 0;
}
