#include "../common.h"

int main() {
    int len;
    printf("moi nhap vao so luong phan tu ");
    scanf("%d", &len);
    int *arr = (int *)malloc(sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", arr + i);
    }
    int number_search;
    printf("moi nhap vao so muon tim kíem ");
    scanf("%d", &number_search);
    for (int i = 0; i < len; i++) {
        if (arr[i] == number_search) {
            printf("%d ",i);
            return 1;
        }
free(arr);
    return 0;
}