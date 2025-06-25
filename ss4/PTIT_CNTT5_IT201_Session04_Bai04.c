//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int main() {
    int len;
    printf("nhao do dai cau mang: ");
    scanf("%d", &len);
    int index=0;
    int *arr = (int*)malloc(len*sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    int number_search;
    scanf("%d",&number_search);
    for (int i = 1; i < len; i++) {
        if (arr[i]=number_search) {
            index = i;
            number_search=arr[i];
        }
    }
    printf("%d",index);
    free(arr);
    return 0;
}