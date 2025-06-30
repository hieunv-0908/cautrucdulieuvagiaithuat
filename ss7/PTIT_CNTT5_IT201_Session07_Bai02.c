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
    int min_index;
    for (int i = 0; i < n; i++) {
        min_index = i;
        for (int j = 0; j < n; j++) {
            if (arr[min_index]<arr[j]) {
                min_index = j;
            }
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    printf("\nAfter:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
