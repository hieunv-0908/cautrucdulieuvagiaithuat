#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Số lượng phần tử không hợp lệ\n");
        return 1;
    }

    int arr[MAX_SIZE], even[MAX_SIZE], odd[MAX_SIZE];
    int i, evenCount = 0, oddCount = 0;

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        } else {
            odd[oddCount++] = arr[i];
        }
    }

    for (i = 0; i < evenCount - 1; i++) {
        for (int j = i + 1; j < evenCount; j++) {
            if (even[i] > even[j]) {
                int temp = even[i];
                even[i] = even[j];
                even[j] = temp;
            }
        }
    }

    for (i = 0; i < oddCount - 1; i++) {
        for (int j = i + 1; j < oddCount; j++) {
            if (odd[i] < odd[j]) {
                int temp = odd[i];
                odd[i] = odd[j];
                odd[j] = temp;
            }
        }
    }

    printf("[");
    for (i = 0; i < evenCount; i++) {
        printf("%d", even[i]);
        if (i != n - 1) printf(", ");
    }
    for (i = 0; i < oddCount; i++) {
        if (evenCount + i != 0) printf(", ");
        printf("%d", odd[i]);
    }
    printf("]\n");

    return 0;
}
