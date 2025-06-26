//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int total_arr(int *arr,int len,int left,int total);

int main() {
    int *arr = malloc(sizeof(int) * 100);
    int len;
    printf("Enter the length of array : ");
    scanf("%d",&len);
    for (int i = 0; i < len; i++) {
        scanf("%d",&arr[i]);
        while (getchar() != '\n');
    }
    int total=0;
    total=total_arr(arr,len,0,total);
    printf("The total number is : %d",total);

    return 0;
}

int total_arr(int *arr,int len,int left,int total) {
    if (left <len) {
        total+=arr[left];
        return total_arr(arr,len,left+1,total);
    }
    return total;
}