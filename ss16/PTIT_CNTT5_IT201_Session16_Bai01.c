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



int main() {
    QUEUE q;
    init(&q);

}