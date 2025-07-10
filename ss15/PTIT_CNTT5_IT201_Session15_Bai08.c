#include "../common.h"

#define MAX 100

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
    Person items[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front > q->rear;
}

int is_full(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, Person p) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = p;
}

Person dequeue(Queue *q) {
    Person nullPerson = {"", -1};
    if (is_empty(q)) {
        return nullPerson;
    }
    Person p = q->items[q->front];
    q->front++;
    return p;
}

void serve_customer(Queue *queueOld, Queue *queueNormal) {
    Person p;
    if (!is_empty(queueOld)) {
        p = dequeue(queueOld);
    } else if (!is_empty(queueNormal)) {
        p = dequeue(queueNormal);
    } else {
        printf("No customers in queue.\n");
        return;
    }
    printf("Serving: %s (Age: %d)\n", p.name, p.age);
}

int main() {
    Queue queueOld, queueNormal;
    init(&queueOld);
    init(&queueNormal);

    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        Person p;
        printf("Enter name: ");
        fgets(p.name, sizeof(p.name), stdin);
        p.name[strcspn(p.name, "\n")] = '\0';

        printf("Enter age: ");
        scanf("%d", &p.age);
        getchar();

        if (p.age >= 60) {
            enqueue(&queueOld, p);
        } else {
            enqueue(&queueNormal, p);
        }
    }

    printf("\n--- Serving customers ---\n");
    while (!is_empty(&queueOld) || !is_empty(&queueNormal)) {
        serve_customer(&queueOld, &queueNormal);
    }

    return 0;
}
