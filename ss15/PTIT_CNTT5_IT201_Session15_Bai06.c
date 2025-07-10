#include "../common.h"

#define MAX 101

struct Queue {
    char *client[MAX];
    int front;
    int rear;
};

void init(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int empty(struct Queue *q) {
    return q->front > q->rear;
}

int is_full(struct Queue *q) {
    return q->rear == MAX - 1;
}

void add(struct Queue *q) {
    if (is_full(q)) {
        printf("Cannot add new client. Queue is full.\n");
        return;
    }
    char temp[30];
    printf("Enter client name: ");
    getchar(); // clear buffer if needed
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = 0;

    q->rear++;
    q->client[q->rear] = malloc(strlen(temp) + 1);
    strcpy(q->client[q->rear], temp);
}

void pop(struct Queue *q) {
    if (empty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Popped client: %s\n", q->client[q->front]);
    free(q->client[q->front]);
    q->front++;
}

void display(struct Queue *q) {
    if (empty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Clients in queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s\n", q->client[i]);
    }
}

int main() {
    struct Queue queue;
    init(&queue);

    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add client\n");
        printf("2. Pop client\n");
        printf("3. Display clients\n");
        printf("4. Check if empty\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(&queue);
                break;
            case 2:
                pop(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                if (empty(&queue))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 5:
                // Free memory before exit
                for (int i = queue.front; i <= queue.rear; i++) {
                    free(queue.client[i]);
                }
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
