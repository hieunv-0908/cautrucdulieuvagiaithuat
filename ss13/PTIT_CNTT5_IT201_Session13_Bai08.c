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

int is_matching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

void check_bracket(const char *expr) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (is_empty(&s) || !is_matching(pop(&s), ch)) {
                printf("false\n");
                return;
            }
        }
    }
}

int main () {
        char input[MAX];
        printf("Enter a bracket expression: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Xoá '\n' nếu có
        check_bracket(input);
        return 0;
}