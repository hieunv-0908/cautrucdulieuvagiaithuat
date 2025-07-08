#include "../common.h"

#define MAX 100

typedef struct Stack {
    char data[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

char top(Stack* s) {
    return s->data[s->top];
}

void push(Stack* s, char c) {
    if (s->top < MAX - 1)
        s->data[++s->top] = c;
}

char pop(Stack* s) {
    if (!is_empty(s))
        return s->data[s->top--];
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infix_to_postfix(char* infix, char* postfix) {
    Stack s;
    init(&s);
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isdigit(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!is_empty(&s) && top(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else if (is_operator(c)) {
            while (!is_empty(&s) && precedence(top(&s)) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (!is_empty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Nhập biểu thức infix: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Biểu thức postfix: %s\n", postfix);

    return 0;
}
