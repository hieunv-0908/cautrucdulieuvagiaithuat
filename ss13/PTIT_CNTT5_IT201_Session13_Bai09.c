#include "../common.h"

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = value;
    } else {
        printf("Ngăn xếp đầy!\n");
    }
}

int pop(Stack* s) {
    if (!is_empty(s)) {
        return s->data[s->top--];
    } else {
        printf("Ngăn xếp rỗng!\n");
        return 0;
    }
}

int evaluate_postfix(char* expr) {
    Stack s;
    init(&s);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Toán tử không hợp lệ: %c\n", ch);
                    return 0;
            }

            push(&s, result);
        }
    }

    return pop(&s);
}

int main() {
    char expr[MAX];

    printf("Nhập biểu thức hậu tố: ");
    scanf("%s", expr);

    int result = evaluate_postfix(expr);
    printf("Kết quả: %d\n", result);

    return 0;
}
