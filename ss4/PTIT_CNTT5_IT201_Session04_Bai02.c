
#include "../common.h"

int main() {
    int len;
    printf("nhao do dai cau mang: ");
    scanf("%d", &len);
    int index=0;
    int *arr = (int*)malloc(len*sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    int number_max=arr[0];
    for (int i = 1; i < len; i++) {
        if (number_max<arr[i]) {
            index = i;
            number_max=arr[i];
        }
    }
    printf("%d\n",index);
    free(arr);
    return 0;
}