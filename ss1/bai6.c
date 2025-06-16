#include <stdio.h>

int main() {
    int arr[] = {1,2,3,15,5,15,7,14,9,10,11,12,13,14,15};
    int number;
    scanf("%d",&number);
    int count = 0;
    for(int i=0;i<sizeof(arr) / sizeof(arr[0]);i++) {
        if (arr[i] == number ) {
            count++;
        }
    }
    printf("%d \n %d",number,count);
}

// độ phức tpaj về thời gian là O(n)
// độ phức tạp về khng gian là O(1)