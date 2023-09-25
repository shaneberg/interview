#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#define MAX_LINE_SIZE 120

char g_line[MAX_LINE_SIZE];
size_t g_write_pos = 0;

void reset_line() {
    g_write_pos = 0;
    g_line[g_write_pos] = '\0';
}

void print_line() {
    printf("%s\n", g_line);
}

void write_chars_to_line(const char character, const size_t count) {

    if (count == 0) {
        return;
    }

    const size_t remaining = ARRAY_SIZE(g_line) - g_write_pos - 1;

    const size_t to_write = MIN(count, remaining);

    memset(g_line + g_write_pos, character, to_write);
    g_write_pos += to_write;
    g_line[g_write_pos] = '\0';
}

void square_pattern_for_char(const char character, const size_t size) {
    printf("== Square Pattern %zu ==\n", size);

    for (size_t i = 0; i < size; i++) {
        reset_line();

        write_chars_to_line(character, size);

        print_line();
    }

    printf("========================\n");
}

void square_pattern(const size_t size) {
    return square_pattern_for_char('*', size);
}

void hollow_square_pattern_for_char(const char character, const size_t size) {
    printf("== Hollow Square Pattern %zu ==\n", size);

    const size_t space_count = size - MIN(2, size);

    for (size_t i = 0; i < size; i++) {
        reset_line();

        const bool is_border = (i == 0 || i == size - 1);
        const char inner_mark = is_border ? character : ' ';

        write_chars_to_line(character, 1);
        write_chars_to_line(inner_mark, space_count);
        write_chars_to_line(character, size > 1 ? 1 : 0);

        print_line();
    }

    printf("===============================\n");
}

void hollow_square_pattern(const size_t size) {
    return hollow_square_pattern_for_char('*', size);
}

void right_triangle_pattern_for_char(const char character, const size_t size) {
    printf("== Right Triangle Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        reset_line();

        const size_t mark_count = i + 1;
        const size_t space_count = size - mark_count;
        write_chars_to_line(' ', space_count);
        write_chars_to_line(character, mark_count);

        print_line();
    }

    printf("================================\n");
}

void right_triangle_pattern(const size_t size) {
    return right_triangle_pattern_for_char('*', size);
}

void left_triangle_pattern_for_char(const char character, const size_t size) {
    printf("== Left Triangle Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        reset_line();
        write_chars_to_line(character, i + 1);
        print_line();
    }

    printf("=============================\n");
}

void left_triangle_pattern(const size_t size) {
    return left_triangle_pattern_for_char('*', size);
}

void reverse_pyramid_pattern_for_char(const char character, const size_t size) {
    printf("== Reverse Pyramid Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        reset_line();

        const size_t mark_count = (size * 2) - ((i * 2) + 1);
        const size_t space_count = i;

        write_chars_to_line(' ', space_count);
        write_chars_to_line(character, mark_count);

        print_line();
    }

    printf("===========================\n");
}

void reverse_pyramid_pattern(const size_t size) {
    return reverse_pyramid_pattern_for_char('*', size);
}

void hollow_pyramid_pattern_for_char(const char character, const size_t size) {

    printf("== Hollow Pyramid Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        reset_line();

        const size_t mark_count = (i * 2) + 1;
        const size_t space_count = size - i;

        const size_t inner_space_count = mark_count - MIN(2, mark_count);
        const char inner_spaces_mark = (i == 0 || i == size - 1) ? character : ' ';

        write_chars_to_line(' ', space_count);
        write_chars_to_line(character, 1);
        write_chars_to_line(inner_spaces_mark, inner_space_count);
        write_chars_to_line(character, mark_count > 2 ? 1 : 0);

        print_line();
    }

    printf("=======================\n");
}

void hollow_pyramid_pattern(const size_t size) {
    return hollow_pyramid_pattern_for_char('*', size);
}

void downward_triangle_pattern_for_char(const char character, const size_t size) {
    printf("== Downward Triangle Pattern %zu ==\n", size);

    for (size_t i = 0; i < size; i++) {
        reset_line();
        write_chars_to_line(character, size - i);
        print_line();
    }

    printf("=============================\n");
}

void downward_triangle_pattern(const size_t size) {
    return downward_triangle_pattern_for_char('*', size);
}

void hollow_triangle_pattern_for_char(const char character, const size_t size) {
    printf("== Hollow Triangle Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        reset_line();

        const bool is_boundary = (i == 0) || (i == size - 1);

        const size_t cur_width = i + 1;

        const size_t space_count = cur_width - MIN(2, cur_width);
        const char inner_mark = is_boundary ? character : ' ';

        write_chars_to_line(character, 1);
        write_chars_to_line(inner_mark, space_count);
        write_chars_to_line(character, (i == 0) ? 0 : 1);

        print_line();
    }

    printf("=============================\n");
}

void hollow_triangle_pattern(const size_t size) {
    return hollow_triangle_pattern_for_char('*', size);
}

void pyramid_pattern_for_char(const char character, const size_t size) {
    printf("== Pyramid Pattern %zu ==\n", size);
    for (size_t i = 0; i < size; i++) {
        reset_line();

        const size_t mark_count = (i * 2) + 1;
        const size_t space_count = size - (i + 1);

        write_chars_to_line(' ', space_count);
        write_chars_to_line(character, mark_count);

        print_line();
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
        reset_line();

        const bool top = (i < size);

        const size_t space_count = top ? size - MIN(size, (i + 1)) : (i - size) + 1;
        write_chars_to_line(' ', space_count);

        const size_t mark_count = top ? (i * 2) + 1 : ((size - 1) * 2) - ((i - size) * 2 + 1);
        write_chars_to_line(character, mark_count);

        print_line();
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
        reset_line();

        const bool top = (i < size);
        const size_t space_count = top ? size - MIN(size, (i + 1)) : (i - size) + 1;
        const size_t mark_count = top ? (i * 2) + 1 : ((size - 1) * 2) - ((i - size) * 2 + 1);
        const size_t inner_space_count = mark_count - MIN(mark_count, 2);
        const bool is_boundary = (i == 0 || i == total_size - 1);

        write_chars_to_line(' ', space_count);
        write_chars_to_line(character, 1);
        write_chars_to_line(' ', inner_space_count);
        write_chars_to_line(character, is_boundary ? 0 : 1);

        print_line();
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
