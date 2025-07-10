//
// Created by Admin on 11/07/2025.
//
#include "../common.h"

typedef struct NODE{
    int data;
    struct NODE *next;
}NODE;

typedef struct QUEUE{
    NODE *front, *near;
}QUEUE;

void init(QUEUE *q){
    q->front = q->near = NULL;
}

int isEmpty(QUEUE *q){
    return q->front == NULL;
}

void enqueue(QUEUE *q){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;
    if(isEmpty(q)){
        q->front = q->near = new_node;
        return;
    }
    q->near->next = new_node;
    q->near = new_node;
}

void display(QUEUE *q){
    NODE *temp = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    QUEUE q;
    init(&q);
    for(int i = 0; i < 5; i++){
        enqueue(&q);
    }
    display(&q);
    return 0;
}