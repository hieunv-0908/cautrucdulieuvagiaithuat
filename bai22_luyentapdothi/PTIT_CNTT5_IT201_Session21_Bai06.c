#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[MAX];  // Danh sách kề
int visited[MAX];  // Đánh dấu đã thăm

Node* create_node(int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = v;
    new_node->next = NULL;
    return new_node;
}

void add_edge(int u, int v) {
    Node* node_v = create_node(v);
    node_v->next = adj[u];
    adj[u] = node_v;

    Node* node_u = create_node(u);
    node_u->next = adj[v];
    adj[v] = node_u;
}

void DFS(int u) {
    visited[u] = 1;
    printf("%d ", u);
    Node* temp = adj[u];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFS(temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int v, e;
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    // Khởi tạo danh sách kề
    for (int i = 0; i < v; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        add_edge(u, w);
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(start);
    printf("\n");

    return 0;
}
