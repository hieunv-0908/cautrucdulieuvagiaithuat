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
    int left=0, right=len-1;
    while(left<=right) {
        int mind = (left+right)/2;
        if(arr[mind]==number_search) {
            printf("da tim thay:");
            printf("da tim thay:%d ở:%d",arr[mind],mind);

            return 1;
        }else if(arr[mind]>number_search) {
            right = mind-1;
        }else {
            left = mind+1;
        }
    }
    free(arr);
    return 0;
}