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
    int number;
    printf("Enter number search please:\n");
    scanf("%d",&number);
    while (getchar()!='\n');
    int l = 0,r=n-1;
    int m = (l+r)/2;
    while (l<=r) {
        if (arr[m] == number) {
            printf("o vi tri %d",m+1);
            break;
        }else if (arr[m] < number) {
            l = m-1;
            m = (l+r)/2;
        }else {
            r = m+1;
            m = (l+r)/2;
        }
    }

    printf("\n");
    printf("Do phuc tap thoi gian tot nhat là O(1) neu phan tu can tim la phan tu o giua trong mang");
    printf("\n");
    printf("Do phuc tap thoi gian xau nhat la O(log n) neu phan tu can tim khong phai phan tu o giua mang trong mang");

    return 0;
}
