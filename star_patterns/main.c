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

void hollow_triangle_pattern_for_char(const char character, const size_t size) {
    printf("== Hollow Triangle Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        const bool is_boundary = (i == 0) || (i == size - 1);

        const size_t cur_width = i + 1;
        const char right_boundary = cur_width > 1 ? character : '\0';

        const size_t space_count = cur_width - MIN(2, cur_width);
        const char space = is_boundary ? character : ' ';

        char* spaces = generate_n_chars(space, space_count);
        if (spaces) {
            printf("%c%s%c\n", character, spaces, right_boundary);
            free(spaces);
        }
    }

    printf("=============================\n");
}

void hollow_triangle_pattern(const size_t size) {
    return hollow_triangle_pattern_for_char('*', size);
}

void downward_triangle_pattern_for_char(const char character, size_t size) {
    printf("== Downward Triangle Pattern %zu ==\n", size);

    for (size_t i = 0; i < size; i++) {
        char* marks = generate_n_chars(character, size - i);
        if (marks) {
            printf("%s\n", marks);
            free(marks);
        }
    }

    printf("=============================\n");
}

void downward_triangle_pattern(const size_t size) {
    return downward_triangle_pattern_for_char('*', size);
}

void left_triangle_pattern_for_char(const char character, const size_t size) {
    printf("== Left Triangle Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        char* marks = generate_n_chars(character, i + 1);
        if (marks) {
            printf("%s\n", marks);
            free(marks);
        }
    }

    printf("=============================\n");
}

void left_triangle_pattern(const size_t size) {
    return left_triangle_pattern_for_char('*', size);
}

void right_triangle_pattern_for_char(const char character, const size_t size) {
    printf("== Right Triangle Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        const size_t mark_count = i + 1;
        const size_t space_count = size - mark_count;

        char* spaces = generate_n_chars(' ', space_count);
        char* marks = generate_n_chars(character, mark_count);

        if (spaces && marks) {
            printf("%s%s\n", spaces, marks);
        }

        if (spaces) {
            free(spaces);
        }

        if (marks) {
            free(marks);
        }
    }

    printf("================================\n");
}

void right_triangle_pattern(size_t size) {
    return right_triangle_pattern_for_char('*', size);
}

void hollow_square_pattern_for_char(const char character, size_t size) {
    printf("== Hollow Square Pattern %zu ==\n", size);

    const char left_boundary = character;
    const char right_boundary = size > 1 ? character : '\0';
    const size_t space_count = size - MIN(2, size);

    for (size_t i = 0; i < size; i++) {
        const bool is_border = (i == 0 || i == size - 1);
        const char c = is_border ? character : ' ';
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
    right_triangle_pattern(0);
    right_triangle_pattern(1);
    right_triangle_pattern(2);
    right_triangle_pattern(3);
    right_triangle_pattern(4);
    right_triangle_pattern(5);
    left_triangle_pattern(0);
    left_triangle_pattern(1);
    left_triangle_pattern(2);
    left_triangle_pattern(3);
    left_triangle_pattern(4);
    left_triangle_pattern(5);
    downward_triangle_pattern(0);
    downward_triangle_pattern(1);
    downward_triangle_pattern(2);
    downward_triangle_pattern(3);
    downward_triangle_pattern(4);
    downward_triangle_pattern(5);
    hollow_triangle_pattern(0);
    hollow_triangle_pattern(1);
    hollow_triangle_pattern(2);
    hollow_triangle_pattern(3);
    hollow_triangle_pattern(4);
    hollow_triangle_pattern(5);
    hollow_triangle_pattern(6);
    hollow_triangle_pattern(7);
    hollow_triangle_pattern(8);
    hollow_triangle_pattern(9);
    hollow_triangle_pattern(10);
    return 0;
}
