//
// Created by Admin on 21/07/2025.
//
#include "../common.h"

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node *create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

Node* create_tree(Node *root,int value) {
    if(root == NULL) {
        return create_node(value);
    }
    if (value < root->data) {
        root->left = create_tree(root->left, value);
    }else {
        root->right = create_tree(root->right, value);
    }
    return root;
}

void display_tree(Node *root) {
    if (root != NULL) {
        printf("%d \n",root->data);
        display_tree(root->left);
        display_tree(root->right);
    }
}

int main() {
    Node *root = NULL;
    for (int i = 0; i <= 10; i++) {
        root = create_tree(root, i);
    }
    display_tree(root);
    return 0;
}