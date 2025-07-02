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

int main() {
    struct NODE *head = NULL;
    append_node(&head,1);
    for (int i = 0; i < 4; i++) {
        printf("Nhap vao gia tri cua phan tu so %d cua danh sach:",i+1);
        int value;
        scanf("%d", &value);
        while (getchar() != '\n');
        append_node(&head,value);
    }
    struct NODE *current = head;
    printf("head-->");
    while (current != NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    int number_search;
    printf("NULL \n");
    printf("nhap vao gia tri muon tim trong danh sach:");
    scanf("%d",&number_search);
    while (getchar() != '\n');
    search_data_node(&head,number_search);
    return 0;
}
