//
// Created by Admin on 16/06/2025.
//
#include <stdio.h>

void printMatrix(int matrix[][100], int rows, int cols) {
    printf("Toan bo ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void printDiagonal(int matrix[][100], int size) {
    printf("Duong cheo chinh:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

int main() {
    int matrix[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rows = 3, cols = 3;

    printMatrix(matrix, rows, cols);
    printDiagonal(matrix, rows);

    return 0;
}

/*
Thời gian: O(n * m)
Không gian: O(1)
 */

/*
Thời gian: O(n)
Không gian: O(1)
 */