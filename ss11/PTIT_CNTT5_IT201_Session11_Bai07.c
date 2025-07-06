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
    while (current->next != NULL)
        current = current->next;
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

void insert_at_position(struct NODE** head, int value, int position) {
    if (position < 0) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    struct NODE* new_node = create_node(value);

    if (position == 0) {
        new_node->next = *head;
        if (*head != NULL)
            (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    struct NODE* current = *head;
    int index = 0;

    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        printf("Vi tri vuot qua do dai danh sach.\n");
        free(new_node);
        return;
    }

    new_node->next = current->next;
    new_node->prev = current;

    if (current->next != NULL)
        current->next->prev = new_node;

    current->next = new_node;
}

int main() {
    struct NODE* head = NULL;
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        append_node(&head, values[i]);
    }

    printf("Danh sach ban dau:\n");
    print_list(&head);

    int value, pos;
    printf("Nhap gia tri muon chen: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon chen (bat dau tu 0): ");
    scanf("%d", &pos);
    insert_at_position(&head, value, pos);

    printf("Danh sach sau khi chen:\n");
    print_list(&head);

    return 0;
}
