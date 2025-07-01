#include <stdio.h>

#define MAX_SIZE 1000

// Hàm trộn hai mảng con
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left,  mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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

    if (n <= 0 || n >= 1000) {
        printf("Số lượng phần tử không hợp lệ\n");
        return 1;
    }

    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    print_array(arr, n, "before");

    merge_sort(arr, 0, n - 1);

    print_array(arr, n, "after");

    printf("Do phuc tap thoi gian la o(n log n) \n");
    printf("Do phuc tap khong gian la o(n) \n");

    return 0;
}

