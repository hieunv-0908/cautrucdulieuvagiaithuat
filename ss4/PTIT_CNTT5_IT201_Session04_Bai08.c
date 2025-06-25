//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int main() {
    int memory;
    int check=0;
    printf("Moi ban nhap vao so luong bo nho muon cap phat:");
    scanf("%d",&memory);
    while (getchar() != '\n');
    int *arr = (int*)malloc(memory*sizeof(int));
    int len;
    printf("moi nhap vao do dai cua mang:");
    scanf("%d",&len);
    while (getchar() != '\n');
    for (int i = 0; i < len; i++) {
        scanf("%d",&arr[i]);
        while (getchar() != '\n');
    }
    int number_search;
    printf("nhap vao phan tu muon tim kiem:");
    scanf("%d",&number_search);
    while (getchar() != '\n');
    for (int i=0; i<len; i++) {
        if (arr[i] == number_search) {
            printf("vi tri:%d \n",i);
            check =1;
        }
    }

    if (!check) {
        printf("phan tu khong co trong mang");
    }

    free(arr);
    return 0;
}