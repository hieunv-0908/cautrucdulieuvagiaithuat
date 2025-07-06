#include    "../common.h"

struct NODE {
    int data;
    struct NODE* next;
    struct NODE* prev;
};

struct NODE* create_node(int value) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void append(struct NODE** head, int value) {
    struct NODE* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct NODE* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void print_forward(struct NODE* head) {
    struct NODE* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct NODE* head = NULL;
    append(&head, 10);
    append(&head, 25);
    append(&head, 33);
    append(&head, 47);
    append(&head, 59);

    print_forward(head);

    return 0;
}
