//
// Created by Admin on 10/07/2025.
//
#include "../common.h"
#define MAX 100

struct Queue{
    int item[MAX];
    int front;
    int rear;
};
/*
void init(struct Queue *q){
    q->front = q->rear = NULL;
}

int empty(struct Queue *q){
    return q->front == NULL;
}

void enqueue(struct Queue *q, int data){
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->next = NULL;
    if(empty(q)){
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}
*/
void init(struct Queue *q){
    q->front = 0;
    q->rear = -1;
}

int empty(struct Queue *q){
    return q->front == 0 || q->rear == -1;
}

int is_full(struct Queue *q){
    return q->rear == MAX-1;
}

void add(struct Queue *q){
    if(is_full(q)){
        printf("Queue is full\n");
        return;
    }
    int item;
    printf("Enter item : ");
    scanf("%d",&item);
    q->rear++;
    q->item[q->rear] = item;
}

void del(struct Queue *q){
    if(empty(q)){
        printf("Queue is empty\n");
        return;
    }
    int item = q->item[q->front];
     q->front++;
}

int main() {
    struct Queue queue;
    init(&queue);
}