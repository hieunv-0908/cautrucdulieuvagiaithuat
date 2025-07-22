//
// Created by Admin on 22/07/2025.
//
#include "../common.h"


typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *create_node_tree(Node *root,int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *create_tree(Node *root, int value) {
    Node *new_node = create_node_tree(root,value);
    if (root == NULL) {
        return new_node;
    }
    if (root->left == NULL) {
        root->left = new_node;
    }else if (root->right ==NULL) {
        root->right = new_node;
    }else {
        create_tree(root->left,value);
    }
    return root;
}

Node* create_tree_bst(Node *root,int value) {
    Node *new_node = create_node_tree(root,value);
    if (root == NULL) {
        return new_node;
    }
    if (new_node->data < root->data) {
        root->left = create_tree_bst(root->left,value);
    }else if (new_node->data > root->data) {
        root->right = create_tree_bst(root->right,value);
    }
    return root;
}

Node* insert_tree_bst(Node *root,int value) {
    Node *new_node = create_node_tree(root,value);
    if (root == NULL) {
        return new_node;
    }
    if (new_node->data < root->data) {
        root->left = create_tree_bst(root->left,value);
    }else if (new_node->data > root->data) {
        root->right = create_tree_bst(root->right,value);
    }
    return root;
}

void display_tree_bt_dfs_preorder(Node *root){
    if (root!=NULL) {
        printf("%d",root->data);
        display_tree_bt_dfs_preorder(root->left);
        display_tree_bt_dfs_preorder(root->right);
    }
}

int count_tree_node(Node *root){
    if (root==NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return count_tree_node(root->left) + count_tree_node(root->right);
}

int count_tree_height(Node *root){
    if (root==NULL) {
        return 0;
    }

    int left_height = count_tree_height(root->left);
    int right_height = count_tree_height(root->right);
    return 1 + (left_height > right_height ? left_height:right_height);
}

int search_max(Node *root) {
    if (root == NULL) {
        return INT_MIN;
    }

    int left_max = search_max(root->left);
    int right_max = search_max(root->right);

    int max_data = root->data;
    if (left_max > max_data) max_data = left_max;
    if (right_max > max_data) max_data = right_max;

    return max_data;
}

int search_data(Node *root,int value) {
    if (root == NULL) {
        return 0;
    }
    if (value != root->left->data) {
        return 1 + search_data(root->left,value);
    }
    if (value != root->right->data) {
        return 1 + search_data(root->right,value);
    }
}

int find_level(Node* root, int target) {
    if (root == NULL) return -1;

    Node* queue[1000];
    int level[1000];
    int front = 0, rear = 0;

    queue[rear] = root;
    level[rear++] = 1;

    while (front < rear) {
        Node* current = queue[front];
        int current_level = level[front];
        front++;

        if (current->data == target) {
            return current_level;
        }

        if (current->left != NULL) {
            queue[rear] = current->left;
            level[rear++] = current_level + 1;
        }

        if (current->right != NULL) {
            queue[rear] = current->right;
            level[rear++] = current_level + 1;
        }
    }

    return -1;
}

Node *delete_node(Node *root, int value) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == value) {
            free(root);
            return NULL;
        } else {
            printf("Không tìm thấy giá trị %d trong cây.\n", value);
            return root;
        }
    }

    Node *target = NULL, *parent_of_last = NULL;
    Node *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node *current = queue[front++];
        if (current->data == value) {
            target = current;
        }
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }

    if (target == NULL) {
        printf("Không tìm thấy giá trị %d trong cây.\n", value);
        return root;
    }

    Node *last = find_last_node(root, &parent_of_last);
    if (last != NULL) {
        target->data = last->data;

        if (parent_of_last->right == last) {
            parent_of_last->right = NULL;
        } else if (parent_of_last->left == last) {
            parent_of_last->left = NULL;
        }
        free(last);
    }

    return root;
}

int main(){
    Node *root = NULL;
    int value;
    getchar();
    for (int i=0;i<5;i++) {
        scanf("%d",&value);
        create_tree(root,value);
    }
    return 0;
}