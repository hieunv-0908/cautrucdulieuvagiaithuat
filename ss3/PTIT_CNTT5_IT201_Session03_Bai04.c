//
// Created by Admin on 17/06/2025.
//
#include "../common.h"


int lartget_search(int row,int cols, int *memoryPtr);
int smallest_search(int row,int cols,int *memoryPtr);
int main() {
    int row;
    int cols;
    scanf("%d",&row);
    scanf("%d",&cols);
    if (row <=0 || row > 100 || cols <=0 || cols > 100) {
        printf("vuot qua so luong cho phep");
        return 1;
    }
    int *memoryPtr = (int*)malloc(row * cols *sizeof(int));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d",&memoryPtr[i* cols +j]);
        }
    }
    int max_number=lartget_search(row,cols, memoryPtr);
    int min_number=smallest_search(row,cols, memoryPtr);
    printf("so lon nhat %d\n",max_number);
    printf("so nho nhat %d\n",min_number);
    free(memoryPtr);

    return 0;
}

int lartget_search(int row,int cols, int *memoryPtr) {
    int number_max = memoryPtr[0 * cols + 0];
    for (int i=0; i<row; i++) {
        for (int j=0; j<cols; j++) {
            if (number_max < memoryPtr[i * cols +j]) {
                number_max = memoryPtr[i * cols +j];
            }
        }
    }
    return number_max;
}

int smallest_search(int row,int cols,int *memoryPtr) {
    int number_min = memoryPtr[0* cols + 0];
    for (int i=0; i<row; i++) {
        for (int j=0; j<cols; j++) {
            if (number_min > memoryPtr[i * cols +j]) {
                number_min = memoryPtr[i * cols + j];
            }
        }
    }
    return number_min;
}