#include "../common.h"

int partition(int arr[],int left,int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j <= right - 1; j++) {
        if (pivot < arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;
    return i;
}

int sort(int arr[],int left,int right) {
    if (left < right) {
        int mid = partition(arr,left,right);
        sort(arr,left,mid-1);
        sort(arr,mid+1,right);
    }
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("Số lượng phần tử không hợp lệ\n");
        return 1;
    }

    int *arr = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr,0,n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}