#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[MAX];    // Danh sách kề
int visited[MAX];  // Đánh dấu đã thăm

// Queue đơn giản cho BFS
typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

void init_queue(Queue* q) {
    q->front = q->rear = -1;
}

int is_empty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (is_empty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (is_empty(q)) return -1;
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Tạo node mới cho danh sách kề
Node* create_node(int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = v;
    new_node->next = NULL;
    return new_node;
}

// Thêm cạnh vào danh sách kề
void add_edge(int u, int v) {
    Node* node_v = create_node(v);
    node_v->next = adj[u];
    adj[u] = node_v;

    Node* node_u = create_node(u);
    node_u->next = adj[v];
    adj[v] = node_u;
}

// Duyệt đồ thị bằng BFS
void BFS(int start) {
    Queue q;
    init_queue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    while (!is_empty(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->data;
            if (!visited[v]) {
                visited[v] = 1;
                enqueue(&q, v);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int v, e;
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    // Khởi tạo danh sách kề và visited
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
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);
    BFS(start);
    printf("\n");

    return 0;
}
