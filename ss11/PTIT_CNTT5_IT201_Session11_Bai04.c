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
    new_node->prev = current;`
}

void print_list(struct NODE** head) {
    struct NODE* current = *head;
    int count =0;
    printf("head-->");
    while (current != NULL) {
        printf("%d   ",current->data);
        current = current->next;
        count++;
    }
    printf("NULL");
    printf("\n");
    printf("Co %d phan tu",count);
}

void check_element(struct NODE** head) {
    struct NODE* current = *head;
    int number_check;
    printf("Enter number to check: ");
    scanf("%d",&number_check);
    while (current != NULL) {
        if (current->data == number_check) {
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
    for (int i = 0; i < 6; i++) {
        printf("Nhap vao gia tri cua phan tu so %d cua danh sach:",i+1);
        int value;
        scanf("%d", &value);
        append_node(&head,value);
    }
    print_list(&head);

    return 0;
}
