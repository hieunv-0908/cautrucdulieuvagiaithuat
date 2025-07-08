//
// Created by Admin on 30/06/2025.
//
#include "../common.h"

#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
}Stack;

int is_empty(struct Stack *s) {
    return s->top == -1;
}

int is_full(struct Stack *s) {
    return s->top == MAX-1;
}

void init(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, int item) {
    if (is_full(s)) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->items[s->top]=item;
}

void print_stack(struct Stack *s) {
    while (s->top != -1) {
        printf("stack[%d]:%d\n",s->top,s->items[s->top]);
        s->top--;
    }
}

int main () {
    Stack s;
    init(&s);
    int value;
    for (int i = 0; i < 5; i++) {
        printf("Enter a number:");
        scanf("%d", &value);
        push(&s, value);
    }
    print_stack(&s);
    return 0;
}