//
// Created by Admin on 23/07/2025.
//
#include <stdio.h>
#define MAX 100

void addEdge(int graph[][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printGraph(int graph[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    int graph[MAX][MAX] = {0};

    addEdge(graph, 1, 2);

    printGraph(graph, n);
    return 0;
}
