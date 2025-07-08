//
// Created by Admin on 30/06/2025.
//
#include "../common.h"

#define MAX 100

typedef struct Stack {
    char items[MAX];
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

void pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d \n",s->items[s->top]);
    s->top--;
}

void print_stack(struct Stack *s) {
    int i = s->top;
    while (i != -1) {
        printf("stack[%d]:%d\n",s->top,s->items[i]);
        i--;
    }
}

void reverse_stack(struct Stack *s) {
    printf("\nReversed stack\n");
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    int temp;
    int mid = s->top / 2;
    for (int i = 0; i <= mid; i++) {
        temp = s->items[i];
        s->items[i] = s->items[s->top - i];
        s->items[s->top - i] = temp;
    }
}

void check_symmetry(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    int mid = s->top / 2;
    int found=1;
    for (int i = 0; i <= mid; i++) {
        if (s->items[i] != s->items[s->top - i]) {
            found=0;
        }
    }
    if (!found) {
        printf("false\n");
    }else {
        printf("true\n");
    }

}

int main () {
    Stack s;
    init(&s);
    char value;
    for (int i = 0; i < 5; i++) {
        printf("Enter a number:");
        scanf(" %c", &value);
        push(&s, value);
    }
    check_symmetry(&s);
    return 0;
}