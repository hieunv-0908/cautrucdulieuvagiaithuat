//
// Created by Admin on 09/07/2025.
//
#include "../common.h"

struct NODE {
    int data;
    struct NODE *next;
}

struct stack{
    struct NODE *top;
}

void init(struct stack *st){
    st->top= NULL;

}

int is_empty(struct stack *st){
    return st->top==NULL;
}

void push(struct stack *st, int data){
    struct NODE * new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->next = st->top;
    st->top = new_node;
}

int pop(struct stack *st){
    if(is_empty(st)){
        printf("Stack is empty\n");
        return -1;
    }
    struct NODE *temp = st->top;
    return_value = temp->data;
    st->top = st->top->next;
    return return_value;
}

int peek(struct stack *st){
    if(is_empty(st)){
        printf("Stack is empty\n");
        return;
    }
    return st->top->data;
}

int print_stack(struct stack *st){
    if(is_empty(st)){
        printf("Stack is empty\n");
        return -1;
    }
    struct NODE current  = st->top;
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    init(&st);
    for(int i = 1; i     <= 5; i++){
        scanf("%d", &n);
        push(&st, n);
    }
    pop(&st);
    print_stack(&st);
    return 0;
}