#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Given a singly linked list, devise a time- and space-efficient algorithm to find the mth-to-last element of the list.
// Implement your algorithm, taking care to handle relevant error conditions. Define mth to last such that when m = 0
// the last element of the list is returned.

typedef struct node {
    int value;
    struct node* next;
} node;

void print_list(node* head) {
    node* cur_node = head;
    while (cur_node) {
        printf("[%d]", cur_node->value);
        cur_node = cur_node->next;
    }

    printf("[/]\n");
}

node* insert(node* head, int value) {
    node* new_node = malloc(sizeof(node));

    if (new_node) {
        new_node->value = value;
        new_node->next = head;
    }

    return new_node;
}

node* build_linked_list(unsigned int length) {
    const int max_val = 50;
    const int min_val = 0;
    node* head = NULL;
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int val = min_val + rand() % (max_val + 1 - min_val);
        head = insert(head, val);
    }

    return head;
}

void free_linked_list(node* head) {
    node* current = head;
    while (current) {
        node* old = current;
        current = current->next;
        free(old);
    }
}

node* get_mth_from_end(node* head, int m) {
    unsigned int visit_count = 0;
    node* current = head;
    node* trailing = current;

    while (current) {
        visit_count++;
        current = current->next;

        // Only increment the trailing pointer if there's more list.
        if (current && visit_count > m) {
            trailing = trailing->next;
        }
    }

    return trailing;
}

int main() {
    node* head = build_linked_list(10);
    print_list(head);
    printf("%d\n", (get_mth_from_end(head, 0)->value));
    printf("%d\n", (get_mth_from_end(head, 1)->value));
    printf("%d\n", (get_mth_from_end(head, 2)->value));
    printf("%d\n", (get_mth_from_end(head, 3)->value));
    printf("%d\n", (get_mth_from_end(head, 4)->value));
    printf("%d\n", (get_mth_from_end(head, 5)->value));
    printf("%d\n", (get_mth_from_end(head, 6)->value));
    printf("%d\n", (get_mth_from_end(head, 7)->value));
    printf("%d\n", (get_mth_from_end(head, 8)->value));
    printf("%d\n", (get_mth_from_end(head, 9)->value));
    printf("%d\n", (get_mth_from_end(head, 10)->value));
    printf("%d\n", (get_mth_from_end(head, 11)->value));
    free_linked_list(head);
    return 0;
}
