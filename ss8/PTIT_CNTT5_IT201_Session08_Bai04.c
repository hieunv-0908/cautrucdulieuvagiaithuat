#include "../common.h"

int main() {
    int n;
    printf("Enter n please:\n");
    scanf("%d",&n);
    if (n < 0 || n > 1000) return 1;
    int *arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Before:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        int max_index=i;
        for (int j = i; j < n; j++) {
            if (arr[j] > arr[max_index]) {
               max_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
    printf("After:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("Do phuc tap luon la O(n^2) \n");


    return 0;
}
