//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int main() {
    int row,cols;
    int has_extra_diagonal =1;
    int total_main_diagonal =0;
    int total_extra_diagonal =0;
    scanf("%d %d",&row,&cols);
    if (row<=0 && cols<=0) {
        printf("So cot va hang khong hop le\n");
        return 1;
    }else if (cols<=0) {
        printf("so cot khong hop le");
        return 1;
    }else if (row <= 0) {
        printf("So hang khong hop le");
        return 1;
    }
    int *arr = (int*)malloc(row * cols *sizeof(int));
    if (row != cols) {
        has_extra_diagonal = 0;
    }
    for (int i=0; i<row; i++) {
        for (int j=0; j<cols; j++) {
            scanf("%d",&arr[i *cols + j]);
        }
    }
    if (!has_extra_diagonal) {
        printf("Không có đường chéo phụ");
        for (int i=0 ; i<row ; i++) {
            total_main_diagonal += arr[i * cols + i];
        }
        printf("duong cheo chinh = %d",total_main_diagonal);
    }else {
        for (int i=0 ; i<row ; i++) {
            total_main_diagonal += arr[i * cols + i];
        }
        for (int i=0 ; i<row ; i++) {
            total_extra_diagonal += arr[i * cols + (cols - i - 1)];
        }
        printf("duong cheo chinh %d\n",total_main_diagonal);
        printf("duong cheo phu %d\n",total_extra_diagonal);

    }

    return 0;
}