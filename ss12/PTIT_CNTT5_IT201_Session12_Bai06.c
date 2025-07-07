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

void insert_last(struct NODE **head) {
    struct NODE *new_node = create_new_node();
    struct NODE *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    new_node->prev = current;
    new_node->next = current->next;
    current->next = new_node;
    return;
}

void delete_node(struct NODE **head) {
    if (*head == NULL) return;

    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct NODE *current = *head;

    while (current != NULL) {
        if (current->data == data) {
            if (current->prev == NULL) {
                *head = current->next;
                if (*head != NULL)
                    (*head)->prev = NULL;
            }
            else {
                current->prev->next = current->next;
                if (current->next != NULL)
                    current->next->prev = current->prev;
            }
            free(current);
        }
        current = current->next;
    }

    printf("Node with data %d not found.\n", data);
}

int main(){
    struct NODE *head = NULL;

    for(int i = 0; i < 5; i++) {
        append(&head);
    }

    print_list(&head);
    delete_node(&head);
    print_list(&head);
    return 0;
}
