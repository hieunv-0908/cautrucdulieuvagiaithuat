#include "../common.h"

int main() {
    int n;
    printf("Enter n please:\n");
    scanf("%d",&n);
    int *arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Before:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    int temp;
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j]>arr[j-1]) {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nAfter:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
