//
// Created by Admin on 17/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

int total_row(int row,int cols,int **arr);
int main() {
    int row,cols;
    scanf("%d %d",&row,&cols);
    if (row < 0 || cols < 0 || row > 1000 || cols > 1000) {
        return 1;
    }
    int **arr = (int**)malloc(row*sizeof(int*));
    for (int i = 0; i < row; i++) {
        arr[i] = (int*)malloc(cols*sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    int total = total_row(row,cols,arr);
    printf("total = %d\n",total);
    return 0;
}

int total_row(int row,int cols,int **arr) {
    int k;
    scanf("%d",&k);
    k-=1;
    int total = 0;
    for (int i = k; i == k; i++) {
        for (int j = 0; j < cols; j++) {
            total += arr[i][j];
        }
    }
   return total;
}