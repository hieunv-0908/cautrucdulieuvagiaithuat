//
// Created by Admin on 21/07/2025.
//
#include "../common.h"


typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;


Node *create_node(int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *create_tree(Node *root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->data) {
        root->left = create_tree(root->left, value);
    } else {
        root->right = create_tree(root->right, value);
    }
    return root;
}

void display_tree(Node *root) {
    if (root != NULL) {
        printf("%d \n", root->data);
        display_tree(root->left);
        display_tree(root->right);
    }
}

void search_tree(Node *root, int value) {
    if (root != NULL) {
        if (root->data == value) {
            printf("true");
            return;
        }
        search_tree(root->left, value);
        search_tree(root->right, value);
    }
}

#define MAX 100

typedef struct Queue {
    Node *data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = q->rear = 0;
}


int is_empty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, Queue *node) {
    if (q->rear < MAX) {
        q->data[q->rear++] = node;
    }
}


Node *dequeue(Queue *q) {
    if (!is_empty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}


void bfs(Node *root, int value) {
    if (root == NULL) {
        return NULL;
    }
    Queue q;
    init(&q);
    enqueue(&q, root);
    while (!is_empty(&q)) {
        Node *current = dequeue(&q);
        if (current->data == value) {
            printf("TRUE");
            return;
        }

        if (current->left != NULL) enqueue(&q, current->left);
        if (current->right != NULL) enqueue(&q, current->right);
    }
}

void insert_node_tree(Node *root, int value) {
    if (root == NULL) {
        return;
    }
    Queue q;
    init(&q);
    enqueue(&q, root);
    while (!is_empty(&q)) {
        Node *current = dequeue(&q);
        if (current->left == NULL) {
            current->left = create_node(value);
            return;
        } else if (current->right == NULL) {
            current->right = create_node(value);
            return;
        }
        enqueue(&q, current->left);
        enqueue(&q, current->right);
    }
}

int main() {
    Node *root = NULL;
    srand(time(NULL));
    root = create_tree(root, 10);
    for (int i = 0; i < 10; i++) {
        root = create_tree(root, rand() % 100);
    }
    display_tree(root);
    insert_node_tree(root, 100);
    printf("\n");
    display_tree(root);
    return 0;
}
