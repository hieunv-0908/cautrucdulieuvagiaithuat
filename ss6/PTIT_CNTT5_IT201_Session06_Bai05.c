//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

void search_min_max(int i,int n,int arr[],int *max,int *min) {
    if (i>=n) return;
    if (arr[*max]<arr[i]) *max=i;
    if (arr[*min]>arr[i]) *min=i;
    search_min_max(i+1,n,arr,max,min);
}

int main() {
    int *arr = malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++) {
        scanf("%d",&arr[i]);
    }
    int max=0;
    int min=0;
    search_min_max(0,5,arr,&max,&min);
    printf("max=%d min=%d\n",arr[max],arr[min]);
    return 0;
}

