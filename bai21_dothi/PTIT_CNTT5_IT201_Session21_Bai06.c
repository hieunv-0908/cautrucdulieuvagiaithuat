//
// Created by Admin on 23/07/2025.
//
#include "../common.h"
#define MAX 100

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *create_node(int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = value;
    return new_node;
}

void add_node(Node *dothi[],int u,int v) {
    Node *nodeV = create_node(v);
    nodeV->next = dothi[u];
    dothi[u] = nodeV;

    Node *nodeU = create_node(u);
    nodeU->next = dothi[v];
    dothi[v] = nodeU;
}

void printf_dothi(Node *dothi[],int n) {
    for (int i =0;i<n;i++) {
        printf("[%d]:",i);
        Node *temp = dothi[i];
        while (temp!=NULL) {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL \n");
    }
}

int main() {
    Node *dothi[3] = {NULL};
    add_node(dothi,1,2);
    add_node(dothi,0,1);
    add_node(dothi,0,2);
    printf_dothi(dothi,3);
    return 0;
}

