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
    struct NODE* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void print_list(struct NODE** head) {
    struct NODE* current = *head;
    printf("Danh sach: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("<->");
        current = current->next;
    }
    printf("->NULL\n");
}

void delete_first(struct NODE** head) {
    if (*head == NULL) {
        printf("Danh sach rong. Khong co gi de xoa.\n");
        return;
    }
    struct NODE* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}

int main() {
    struct NODE* head = NULL;
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        append_node(&head, values[i]);
    }

    printf("Ban dau:\n");
    print_list(&head);

    delete_first(&head);

    printf("Sau khi xoa phan tu dau:\n");
    print_list(&head);

    return 0;
}
