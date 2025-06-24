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
    for (int i = 0; i < len/2; i++) {
        if (arr[i] == arr[len-i-1]) {
            printf("cap doi xung (%d,%d),",arr[i],arr[len-i-1]);
            check = 1;
        }
    }

    if (!check) {
        printf("khong co phan tu doi xung");
    }

    free(arr);
    return 0;
}