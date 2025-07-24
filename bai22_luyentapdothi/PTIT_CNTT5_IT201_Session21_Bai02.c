//
// Created by Admin on 24/07/2025.
//
#include "../common.h"

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *create_node(int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void add_edge(Node *matrix[100],int u,int v) {
    Node *nodeV = create_node(v);
    nodeV->next = matrix[u];
    matrix[u] = nodeV;

    Node *nodeU = create_node(u);
    nodeU->next = matrix[v];
    matrix[v] = nodeU;
}

void display_matrix(Node *matrix[6],int n) {
    for (int i=0; i<n;i++) {
        printf("[%d]:",i);
        Node *temp = matrix[i];
        while (temp!=NULL) {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }
}

int main(){
    Node *matrix[6] = {NULL};
    add_edge(matrix,0,1);
    add_edge(matrix,0,2);
    add_edge(matrix,1,2);
    add_edge(matrix,3,2);
    add_edge(matrix,1,3);
    add_edge(matrix,3,4);
    display_matrix(matrix,6);
}