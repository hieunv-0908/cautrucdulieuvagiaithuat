//
// Created by Admin on 16/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    //c1
    int arr[] = {1,2,3,4,5,6,7,8,9,11,12,13,14,15};
    int arr2[] = {1,2,3,4,5,6,7,8,9,11,12,13,14,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k =0;
    int* arrTemp = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        int check =1;
        for (int j = 0; j < k; j++) {
            if (arrTemp[j] == arr[i]) {
                check =0;
                break;
            }
        }
        if (check == 1) {
            arrTemp[k++] = arr[i] ;
        }
    }
    printf("Mảng không trungd lặp\n");
    for (int i = 0; i < k; i++) {
        printf("%d ",arrTemp[i]);
    }
    printf("\n");
    if (k != n) {
        printf("mang co phan tu trung lap \n");
    }else {
        printf("mang khong co phan tu trung lap \n");
    }
    // độ phức tạp về thời gian là O(n^2)
    // độ pức tạp về không gian là O(n)

    //c2
    k=0;
    for (int i = 0; i < n; i++) {
        int count =0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 1) {
            arrTemp[k++] = arr[i];
        }
    }
    printf("Mảng không trungd lặp\n");
    for (int i = 0; i < k; i++) {
        printf("%d ",arrTemp[i]);
    }
    printf("\n");
    if (k!=n) {
        printf("mang co phan tu trung lap");
    }else {
        printf("mang khong co phan tu trung lap");
    }
}

// độ phức tạp về thời gian là O(n^2)
// độ pức tạp về không gian là O(n)