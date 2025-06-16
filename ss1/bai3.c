#include <stdio.h>
#include <stdlib.h>

int main() {
    int* mallocArray(int n) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i=0; i<n ; i++) {
            arr[i] =i;
        }
        return arr;
    }
    return 0;
}

// độ phức tạp về không gian alf O(n)