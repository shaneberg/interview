#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ARRAY_SIZE(x) (sizeof(x[0]) / sizeof(x))

#define BUFFER_SIZE 120

const bool static_allocation = true;

char g_buffer[BUFFER_SIZE];
size_t g_pos = 0;

void cleanup_chars(char* str) {
    if (static_allocation) {
        g_pos = 0;
    } else if (str) {
        free(str);
    }
}

char* generate_n_chars_static(const char character, const size_t count) {
    char* str = NULL;

    if (count >= ARRAY_SIZE(g_buffer)) {
        str = g_buffer + g_pos;
        memset(str, character, count);
        str[count] = '\0';
        g_pos += count + 1;
    }

    return str;
}

char* generate_n_chars_dynamic(const char character, const size_t count) {

    char* str = malloc(sizeof(character) * (count + 1));

    if (str) {
        memset(str, character, count);
        str[count] = '\0';
    }

    return str;
}

char* generate_n_chars(const char character, const size_t count) {
    if (static_allocation) {
        return generate_n_chars_static(character, count);
    } else {
        return generate_n_chars_dynamic(character, count);
    }
}

void square_pattern_for_char(const char character, const size_t size) {
    printf("== Square Pattern %zu ==\n", size);

    for (size_t i = 0; i < size; i++) {
        char* str = generate_n_chars(character, size);
        if(str) {
            printf("%s\n", str);
        }

        cleanup_chars(str);
    }

    printf("========================\n");
}

void square_pattern(const size_t size) {
    return square_pattern_for_char('*', size);
}

void hollow_square_pattern_for_char(const char character, const size_t size) {
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
        }

        cleanup_chars(spaces);
    }

    printf("===============================\n");
}

void hollow_square_pattern(const size_t size) {
    return hollow_square_pattern_for_char('*', size);
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

        cleanup_chars(spaces);
        cleanup_chars(marks);
    }

    printf("================================\n");
}

void right_triangle_pattern(const size_t size) {
    return right_triangle_pattern_for_char('*', size);
}

void left_triangle_pattern_for_char(const char character, const size_t size) {
    printf("== Left Triangle Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        char* marks = generate_n_chars(character, i + 1);
        if (marks) {
            printf("%s\n", marks);
        }

        cleanup_chars(marks);
    }

    printf("=============================\n");
}

void left_triangle_pattern(const size_t size) {
    return left_triangle_pattern_for_char('*', size);
}

void reverse_pyramid_pattern_for_char(const char character, const size_t size) {
    printf("== Reverse Pyramid Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        const size_t mark_count = (size * 2) - ((i * 2) + 1);
        const size_t space_count = i;

        char* marks = generate_n_chars(character, mark_count);
        char* spaces = generate_n_chars(' ', space_count);

        if (marks && spaces) {
            printf("%s%s\n", spaces, marks);
        }

        cleanup_chars(marks);
        cleanup_chars(spaces);
    }

    printf("===========================\n");
}

void reverse_pyramid_pattern(const size_t size) {
    return reverse_pyramid_pattern_for_char('*', size);
}

void hollow_pyramid_pattern_for_char(const char character, const size_t size) {

    printf("== Hollow Pyramid Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        const size_t mark_count = (i * 2) + 1;
        const size_t space_count = size - i;

        const size_t inner_space_count = mark_count - MIN(2, mark_count);
        const char inner_spaces_mark = (i == 0 || i == size - 1) ? character : ' ';

        const char right_mark = mark_count > 2 ? character : '\0';

        char* spaces = generate_n_chars(' ', space_count);
        char* inner_spaces = generate_n_chars(inner_spaces_mark, mark_count - MIN(2, mark_count));

        if (spaces && inner_spaces) {
            printf("%s%c%s%c\n", spaces, character, inner_spaces, right_mark);
        }

        cleanup_chars(spaces);
        cleanup_chars(inner_spaces);
    }

    printf("=======================\n");
}

void hollow_pyramid_pattern(const size_t size) {
    return hollow_pyramid_pattern_for_char('*', size);
}

void downward_triangle_pattern_for_char(const char character, const size_t size) {
    printf("== Downward Triangle Pattern %zu ==\n", size);

    for (size_t i = 0; i < size; i++) {
        char* marks = generate_n_chars(character, size - i);
        if (marks) {
            printf("%s\n", marks);
        }

        cleanup_chars(marks);
    }

    printf("=============================\n");
}

void downward_triangle_pattern(const size_t size) {
    return downward_triangle_pattern_for_char('*', size);
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
        }

        cleanup_chars(spaces);
    }

    printf("=============================\n");
}

void hollow_triangle_pattern(const size_t size) {
    return hollow_triangle_pattern_for_char('*', size);
}

void pyramid_pattern_for_char(const char character, const size_t size) {
    printf("== Pyramid Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        const size_t mark_count = (i * 2) + 1;
        const size_t space_count = size - (i + 1);
        char* spaces = generate_n_chars(' ', space_count);
        char* marks = generate_n_chars(character, mark_count);

        if (spaces && marks) {
            printf("%s%s\n", spaces, marks);
        }

        cleanup_chars(spaces);
        cleanup_chars(marks);
    }

    printf("====================\n");
}

void pyramid_pattern(const size_t size) {
    return pyramid_pattern_for_char('*', size);
}

void diamond_pattern_for_char(const char character, const size_t size) {
    printf("== Diamond Pattern %zu ==\n", size);

    const size_t total_size = size * 2 - MIN(1, size);

    for (size_t i = 0; i < total_size; i++) {
        const bool top = (i < size);
        const size_t mark_count = top ? (i * 2) + 1 : ((size - 1) * 2) - ((i - size) * 2 + 1);
        const size_t space_count = top ? size - MIN(size, (i + 1)) : (i - size) + 1;

        char* spaces = generate_n_chars(' ', space_count);
        char* marks = generate_n_chars(character, mark_count);

        if (spaces && marks) {
            printf("%s%s\n", spaces, marks);
        }

        cleanup_chars(spaces);
        cleanup_chars(marks);
    }

    printf("=================================\n");
}

void diamond_pattern(const size_t size) {
    return diamond_pattern_for_char('*', size);
}

void hollow_diamond_pattern_for_char(const char character, const size_t size) {
    printf("== Hollow Diamond Pattern %zu ==\n", size);

    const size_t total_size = size * 2 - MIN(1, size);

    for (size_t i = 0; i < total_size; i++) {
        const bool top = (i < size);
        const size_t space_count = top ? size - MIN(size, (i + 1)) : (i - size) + 1;
        const size_t mark_count = top ? (i * 2) + 1 : ((size - 1) * 2) - ((i - size) * 2 + 1);
        const size_t inner_space_count = mark_count - MIN(mark_count, 2);
        const char right_boundary = (i == 0 || i == total_size - 1) ? '\0' : character;

        char* spaces = generate_n_chars(' ', space_count);
        char* inner_spaces = generate_n_chars(' ', inner_space_count);

        if (spaces && inner_spaces) {
            printf("%s%c%s%c\n", spaces, character, inner_spaces, right_boundary);
        }

        cleanup_chars(spaces);
        cleanup_chars(inner_spaces);
    }
    printf("=================================\n");
}

void hollow_diamond_pattern(const size_t size) {
    return hollow_diamond_pattern_for_char('*', size);
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
    pyramid_pattern(0);
    pyramid_pattern(1);
    pyramid_pattern(2);
    pyramid_pattern(3);
    pyramid_pattern(4);
    pyramid_pattern(5);
    pyramid_pattern(6);
    pyramid_pattern(7);
    pyramid_pattern(8);
    pyramid_pattern(9);
    pyramid_pattern(10);
    reverse_pyramid_pattern(0);
    reverse_pyramid_pattern(1);
    reverse_pyramid_pattern(2);
    reverse_pyramid_pattern(3);
    reverse_pyramid_pattern(4);
    reverse_pyramid_pattern(5);
    reverse_pyramid_pattern(6);
    reverse_pyramid_pattern(7);
    reverse_pyramid_pattern(8);
    reverse_pyramid_pattern(9);
    reverse_pyramid_pattern(10);
    hollow_pyramid_pattern(0);
    hollow_pyramid_pattern(1);
    hollow_pyramid_pattern(2);
    hollow_pyramid_pattern(3);
    hollow_pyramid_pattern(4);
    hollow_pyramid_pattern(5);
    hollow_pyramid_pattern(6);
    hollow_pyramid_pattern(7);
    hollow_pyramid_pattern(8);
    hollow_pyramid_pattern(9);
    hollow_pyramid_pattern(10);
    diamond_pattern(0);
    diamond_pattern(1);
    diamond_pattern(2);
    diamond_pattern(3);
    diamond_pattern(4);
    diamond_pattern(5);
    diamond_pattern(6);
    diamond_pattern(7);
    diamond_pattern(8);
    diamond_pattern(9);
    diamond_pattern(10);
    hollow_diamond_pattern(0);
    hollow_diamond_pattern(1);
    hollow_diamond_pattern(2);
    hollow_diamond_pattern(3);
    hollow_diamond_pattern(4);
    hollow_diamond_pattern(5);
    hollow_diamond_pattern(6);
    hollow_diamond_pattern(7);
    hollow_diamond_pattern(8);
    hollow_diamond_pattern(9);
    hollow_diamond_pattern(10);
    return 0;
}
