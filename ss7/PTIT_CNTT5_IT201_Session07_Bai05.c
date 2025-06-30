#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

void print_array(int arr[], int n, const char *label) {
    printf("%s = [", label);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Số lượng phần tử không hợp lệ\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    print_array(arr, n, "before");

    quick_sort(arr, 0, n - 1);

    print_array(arr, n, "after");

    return 0;
}
