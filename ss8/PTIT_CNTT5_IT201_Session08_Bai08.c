#include "../common.h"

void insertionSort(int arr[], int n) {
    if (n <= 0) {
        printf("n khong hop le\n");
        return;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void linearSearch(int arr[], int n) {
    if (n <= 0) return;
    int number_search;
    printf("Moi nhap vao so can tim kiem: ");
    scanf("%d", &number_search);
    for (int i = 0; i < n; i++) {
        if (arr[i] == number_search) {
            printf("Tim thay %d tai vi tri %d\n", arr[i], i);
            return;
        }
    }
    printf("Khong tim thay phan tu trong mang.\n");
}

void binarySearch(int arr[], int n) {
    if (n <= 0) return;

    int found1 = 1, found2 = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) found1 = 0;
        if (arr[i] > arr[i + 1]) found2 = 0;
    }
    if (found1 == 0 && found2 == 0) {
        printf("Mang chua duoc sap xep.\n");
        return;
    }

    int number_search;
    printf("Moi nhap vao so can tim kiem: ");
    scanf("%d", &number_search);
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == number_search) {
            printf("Tim thay %d tai vi tri %d\n", arr[mid], mid);
            return;
        } else if (arr[mid] > number_search) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("Khong tim thay phan tu trong mang.\n");
}

int main() {
    int n = 0;
    int found = 0;
    int select;
    int *arr = NULL;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap mang\n");
        printf("2. In mang\n");
        printf("3. Sap xep (Insertion Sort)\n");
        printf("4. Tim kiem tuyen tinh\n");
        printf("5. Tim kiem nhi phan\n");
        printf("-1000. Thoat\n");
        printf("Moi nhap vao lua chon: ");
        scanf("%d", &select);

        switch (select) {
            case 1:
                printf("Nhap vao so luong phan tu: ");
                scanf("%d", &n);
                free(arr);
                arr = (int*)malloc(n * sizeof(int));
                if (arr == NULL) {
                    printf("Cap phat bo nho that bai!\n");
                    return 1;
                }
                printf("Nhap cac phan tu:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                found = 1;
                break;

            case 2:
                if (!found) {
                    printf("Chua nhap mang.\n");
                    break;
                }
                printf("Mang hien tai: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                if (!found) {
                    printf("Chua nhap mang.\n");
                    break;
                }
                insertionSort(arr, n);
                break;

            case 4:
                if (!found) {
                    printf("Chua nhap mang.\n");
                    break;
                }
                linearSearch(arr, n);
                break;

            case 5:
                if (!found) {
                    printf("Chua nhap mang.\n");
                    break;
                }
                binarySearch(arr, n);
                break;

            case -1000:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (select != -1000);

    free(arr);
    return 0;
}
