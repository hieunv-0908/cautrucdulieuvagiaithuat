#include "../common.h"

struct NODE{
    int data;
    struct NODE *next;
    struct NODE *prev;
};

struct NODE* create_new_node(){
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void append(struct NODE **head){
    struct NODE *new_node = create_new_node();

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct NODE *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    new_node->prev = current;
}

void print_list(struct NODE **head){
    struct NODE *current = *head;
    printf("Head-><-");
    while (current != NULL) {
        printf("%d-><-",current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    struct NODE *head = NULL;

    for(int i = 0; i < 5; i++) {
        append(&head);
    }

    print_list(&head);
    return 0;
}
