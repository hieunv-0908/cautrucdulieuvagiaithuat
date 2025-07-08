//
// Created by Admin on 30/06/2025.
//
#include "../common.h"

typedef struct NODE {
    int data;
    struct NODE *next;
    struct NODE *prev;
}NODE;

void create_new_node(NODE **head) {
    NODE *new_node = malloc(sizeof(NODE));
    int data;
    printf("Enter new data:");
    scanf("%d", &data);
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    }else {
        NODE *current = *head;
        while (current->next !=NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_linked_list(NODE *head) {
    NODE *current = head;
    while (current != NULL) {
        printf("%d",current->data);
        current = current->next;
    }
}

int main () {
    NODE *head = malloc(sizeof(NODE));
    head = NULL;

    return 0;
}