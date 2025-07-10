#include <stdio.h>
#include <stdlib.h>
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

void enqueue(struct Queue *q, int data) {
    if(is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = data;
}

int dequeue(struct Queue *q) {
    if(empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->items[q->front];
    q->front++;
    if(q->front > q->rear) {
        init(q);
    }
    return data;
}

void display(struct Queue *q) {
    if(empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main(){
    struct Queue queue;
    init(&queue);
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        printf("Enter element %d: ", i+1);
        scanf("%d", &x);
        enqueue(&queue, x);
    }
    display(&queue);
    printf("Dequeued element: %d\n", dequeue(&queue));
    display(&queue);
    return 0;
}
