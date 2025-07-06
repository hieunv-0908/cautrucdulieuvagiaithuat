#include "../common.h"

struct NODE {
    int data;
    struct NODE *next;
    struct NODE *prev;
};

struct NODE* create_node(int data) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void append_node(struct NODE** head, int value) {
    struct NODE* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct NODE* tail = *head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = new_node;
    new_node->prev = tail;
}

void insert_at_position(struct NODE** head, int value, int position) {
    if (position < 0) return;
    struct NODE* new_node = create_node(value);

    if (position == 0) {
        new_node->next = *head;
        if (*head) (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    struct NODE* curr = *head;
    int index = 0;
    while (curr != NULL && index < position - 1) {
        curr = curr->next;
        index++;
    }

    if (curr == NULL) {
        free(new_node);
        return;
    }

    new_node->next = curr->next;
    new_node->prev = curr;
    if (curr->next)
        curr->next->prev = new_node;
    curr->next = new_node;
}

void delete_at_position(struct NODE** head, int position) {
    if (*head == NULL || position < 0) return;

    struct NODE* curr = *head;
    int index = 0;

    if (position == 0) {
        *head = curr->next;
        if (*head) (*head)->prev = NULL;
        free(curr);
        return;
    }

    while (curr != NULL &&
