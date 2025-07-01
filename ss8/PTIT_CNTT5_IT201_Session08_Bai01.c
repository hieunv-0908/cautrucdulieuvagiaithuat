#include "../common.h"

int main() {
    int n;
    printf("Enter n please:\n");
    scanf("%d",&n);
    if (n < 0 || n >1000) {
        return 1;
    }
    int *arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Before:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    int m;
    printf("Enter m please:\n");
    scanf("%d",&m);
    for (int i = 0; i < m; i++) {
        if (arr[i] == m) {
            printf("o vi tri %d",i+1);
            break;
        }
    }
    printf("\n");
    printf("Do phuc tap thoi gian tot nhat là O(1) neu phan tu can tim la phan tu dau tien trong mang neu tinh ca viec nhap cac phan tu thi do phuc tap luon la O(n)");
    printf("\n");
    printf("Do phuc tap thoi gian xau nhat la O(n) neu phan tu can tim khong phai phan tu dau tien trong mang");
    return 0;
}
