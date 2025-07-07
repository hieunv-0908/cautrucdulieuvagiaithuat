//
// Created by Admin on 07/07/2025.
//
#include "../common.h"

typedef struct NODE{
    int data;
    struct NODE *next;
    struct NODE *prev;
};

void create_new_node(struct NODE** head){
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct NODE *new_node;
    new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NUll;
    return new_node;
}

void append(struct NODE **head,int data){
    printf("Hay nhap du lieu co node muon them.");
    scanf("%d",&data);
    struct NODE *new_node = create_new_node(head,data);
    struct NODE *current = *head;
    while(current !=NULL){
        if(*head==NULL){
            *head=new_node;
            return;
        }
        new_node->next = current->next;
        current->next = new_node;
        new_node->prev = current;
        current = current->next;
    }


}

int main(){
    struct NODE *head = NULL;
    struct NODE *current = head;
    for(int i=0;i<5;i++) {
        create_new_node(&head);
        current = current->next;
    }
    
}