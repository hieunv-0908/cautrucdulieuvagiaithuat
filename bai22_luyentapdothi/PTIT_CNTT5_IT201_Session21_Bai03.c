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

void add_edge_adj(Node *adj[6],int u,int v) {
    Node *nodeV = create_node(v);
    nodeV->next = adj[u];
    adj[u] = nodeV;

    Node *nodeU = create_node(u);
    nodeU->next = adj[v];
    adj[v] = nodeU;
}

void add_edge_matrix(int matrix[][6],int u,int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void convert(int matrix[][6],Node *adj[6]) {
    for (int v=0;v<6;v++) {
        for (int u=0;u<6;u++) {
            if (matrix[v][u] == 1 && u > v) {
                add_edge_adj(adj,u,v);
            }
        }
    }
}

void display_adj(Node *adj[6],int n) {
    for (int i=0; i<n;i++) {
        printf("[%d]:",i);
        Node *temp = adj[i];
        while (temp!=NULL) {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }
}

void display_matrix(int matrix[][6],int n) {
    for (int i=0; i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    Node *adj[6] = {NULL};

    int matrix[6][6] = {0};
    add_edge_matrix(matrix,0,1);
    add_edge_matrix(matrix,0,2);
    add_edge_matrix(matrix,1,2);
    add_edge_matrix(matrix,3,2);
    add_edge_matrix(matrix,1,3);
    add_edge_matrix(matrix,3,4);
    display_matrix(matrix,6);
    convert(matrix,adj);
    display_adj(adj,6);
}