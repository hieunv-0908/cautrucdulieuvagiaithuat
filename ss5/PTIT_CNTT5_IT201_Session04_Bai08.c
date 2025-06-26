//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int count_paths(int i, int j, int row, int col) {
    if (i == row - 1 && j == col - 1)
        return 1;  // Đến đích
    if (i >= row || j >= col)
        return 0;  // Ra ngoài biên

    return count_paths(i + 1, j, row, col) + count_paths(i, j + 1, row, col);
}


int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int result = count_paths(0, 0, row, col);
    printf("%d\n", result);
    return 0;
    return 0;
}


