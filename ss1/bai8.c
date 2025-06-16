#include <stdio.h>

int main() {
    int arr[] = {1,2,3,10,4,10,5,10,2,3};
    int count_number = 0;
    int number_count_max = 0;
    for(int i=0;i<10;i++) {
        int count = 0;
        int numberCheck = arr[i];
        for(int j=i;j<10;j++) {
            if(numberCheck == arr[j]) {
                count++;
            }
        }
        if(count >= number_count_max) {
            number_count_max = count;
            count_number = numberCheck;
        }
    }
    printf("Number Count: %d\n",count_number);
    printf("Number Count Max: %d\n",number_count_max);
    return 0;
}

// độ phức tạp thời gian O(n^2)
// độ phức tạp không gian là O(n)