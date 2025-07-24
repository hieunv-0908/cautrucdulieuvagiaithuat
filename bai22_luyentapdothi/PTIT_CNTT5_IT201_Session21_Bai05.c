#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void add_edge_matrix(int matrix[][MAX], int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void display_matrix(int matrix[][MAX], int n) {
    printf("Ma tran ke:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(int matrix[][MAX], int n, int k) {
    int count = 0;
    for (int j = 0; j < n; j++) {
        if (matrix[k][j] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, v;
    int matrix[MAX][MAX] = {0};

    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        add_edge_matrix(matrix, u, w);
    }

    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    int result = count_neighbors(matrix, n, k);
    printf("So dinh ke voi %d la: %d\n", k, result);

    return 0;
}
