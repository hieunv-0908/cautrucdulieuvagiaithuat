//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int count_paths(int i, int j, int row, int col,int row_chan,int col_chan) {
    if (i == row - 1 && j == col - 1)
        return 1;  // Đến đích
    if (i==row_chan && j == col_chan)
        return 0;
    if (i >= row || j >= col)
        return 0;  // Ra ngoài biên

    return count_paths(i + 1, j, row, col,row_chan,col_chan) + count_paths(i, j + 1, row, col,row_chan,col_chan);
}


int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int row_chan,col_chan;
    scanf("%d %d", &row_chan, &col_chan);
    while (row_chan>=row || col_chan>=col) {
        scanf("%d %d", &row_chan, &col_chan);
        if (row_chan==-1000) {
            return 0;
        }
    }
    int result = count_paths(0, 0, row, col,row_chan,col_chan);
    printf("%d\n", result);
    return 0;
}


