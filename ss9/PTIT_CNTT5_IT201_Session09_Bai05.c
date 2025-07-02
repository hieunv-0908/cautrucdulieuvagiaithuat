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

void search_data_node(struct NODE** head,int search_data) {
    struct NODE *current = *head;
    while (current != NULL) {
        if (current->data == search_data) {
            printf("TRUE");
            return;
        }
        current = current->next;
    }
    printf("FALSE");
    return;
}

void printf_node(struct NODE** head) {
    struct NODE *current = *head;
    printf("head-->");
    while (current != NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL \n");
    return;
}

void count_node(struct NODE** head) {
    int count = 0;
    if (*head == NULL) {
        printf("Danh sach lien ket khong co phan tu nao ton tai\n");
        return;
    }
    struct NODE *current = *head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("danh sach lien ket co %d phan tu\n", count);
    return;
}

void insert_node(struct NODE** head) {
    struct NODE* new_node = create_node(1);
    struct NODE* current = *head;
    new_node->next = *head;
    *head = new_node;
    return;
}


int main() {
    struct NODE *head = NULL;
    for (int i = 0; i < 4; i++) {
        printf("Nhap vao gia tri cua phan tu so %d cua danh sach:",i+1);
        int value;
        scanf("%d", &value);
        append_node(&head,value);
    }
    printf_node(&head);
    insert_node(&head);
    printf_node(&head);

    return 0;
}
