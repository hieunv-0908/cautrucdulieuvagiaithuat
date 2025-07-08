//
// Created by Admin on 08/07/2025.
//
#include "../common.h"

#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
}Stack;

void init(struct Stack *s) {
    s->top = -1;
}

int main () {
    Stack s;
    init(&s);

    printf("stack moi duoc khoi tao:%d",s.top);
    return 0;
}