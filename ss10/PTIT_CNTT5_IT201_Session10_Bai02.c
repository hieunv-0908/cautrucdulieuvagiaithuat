#include "../common.h"
struct NODE {
    int data;
    struct NODE *next;
};

struct NODE* create_node(int data) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->next = NULL;
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
}

int main() {
    struct NODE *head = NULL;
    for (int i = 0; i < 6; i++) {
        printf("Nhap vao gia tri cua phan tu so %d cua danh sach:",i+1);
        int value;
        scanf("%d", &value);
        append_node(&head,value);
    }
    struct NODE *current = head;
    printf("head-->");
    while (current != NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL");
    return 0;
}
