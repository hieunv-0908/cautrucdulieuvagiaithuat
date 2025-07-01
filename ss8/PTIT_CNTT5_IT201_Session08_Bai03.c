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
    for (int i = 0; i < n-1; i++) {
        int temp;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("After:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\nDo phuc tap tot nhat la O(n) \n");
    printf("Do phuc tap xau nhat la o(n^2) \n");


    return 0;
}
