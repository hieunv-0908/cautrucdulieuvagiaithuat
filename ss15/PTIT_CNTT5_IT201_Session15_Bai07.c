#include <stdio.h>
#define MAX 100

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

void init(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int empty(struct Queue *q) {
    return q->front > q->rear;
}

int is_full(struct Queue *q) {
    return q->rear == MAX - 1;
}

void add(struct Queue *q) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    int item;
    printf("Enter item: ");
    scanf("%d", &item);
    q->rear++;
    q->items[q->rear] = item;
}

void del(struct Queue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int item = q->items[q->front];
    printf("Deleted item: %d\n", item);
    q->front++;
}

void display(struct Queue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

void pop(struct Queue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Popped item: %d\n", q->items[q->front]);
    q->front++;
}

void check(struct Queue *q) {
    if (q->rear - q->front + 1 < 2) {
        printf("Not enough items to check.\n");
        return;
    }

    int ascending = 1;
    for (int i = q->front; i < q->rear; i++) {
        if (q->items[i] + 1 != q->items[i + 1]) {
            ascending = 0;
            break;
        }
    }

    if (ascending) {
        printf("true (items are in consecutive order)\n");
    } else {
        printf("false (items are NOT in consecutive order)\n");
    }
}

int main() {
    struct Queue queue;
    init(&queue);

    for (int i = 0; i < 5; i++) {
        add(&queue);
    }

    display(&queue);
    check(&queue);

    return 0;
}
