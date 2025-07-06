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

void append_node(struct NODE** head,int value) {
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

void prepend_node(struct NODE** head, int value) {
    struct NODE* new_node = create_node(value);
    if (*head != NULL) {
        new_node->next = *head;
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void print_list(struct NODE** head) {
    struct NODE* current = *head;
    int count = 0;
    printf("head-->");
    while (current != NULL) {
        printf("%d   ", current->data);
        current = current->next;
        count++;
    }
    printf("NULL\n");
    printf("Co %d phan tu\n", count);
}

int main() {
    struct NODE *head = NULL;
    for (int i = 0; i < 6; i++) {
        printf("Nhap vao gia tri cua phan tu so %d cua danh sach: ", i+1);
        int value;
        scanf("%d", &value);
        append_node(&head, value);
    }
    print_list(&head);

    int new_value;
    printf("Nhap so nguyen duong de them vao dau danh sach: ");
    scanf("%d", &new_value);
    if (new_value > 0) {
        prepend_node(&head, new_value);
    } else {
        printf("Chi nhap so nguyen duong.\n");
    }

    print_list(&head);
    return 0;
}
