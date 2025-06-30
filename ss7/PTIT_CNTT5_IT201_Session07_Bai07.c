#include <stdio.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("Số lượng phần tử không hợp lệ\n");
        return 1;
    }

    int arr[1000];
    int i;

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before = [");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");

    int temp[1000];
    int index = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            temp[index++] = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == 0) {
            temp[index++] = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        if (arr[i] > 0) {
            temp[index++] = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printf("After = [");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}
