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

void add(struct Queue *q) {
    if(is_full(q)) {
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
    if(empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted: %d\n", q->items[q->front]);
    q->front++;
    if(q->front > q->rear)
        init(q);
}

void display(struct Queue *q) {
    if(empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main(){
    struct Queue queue;
    init(&queue);
    int operations, choice;
    printf("Enter number of operations: ");
    scanf("%d", &operations);
    while(operations--) {
        printf("\n1.Add  2.Delete  3.Display\nChoose: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add(&queue);
                break;
            case 2:
                del(&queue);
                break;
            case 3:
                display(&queue);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
