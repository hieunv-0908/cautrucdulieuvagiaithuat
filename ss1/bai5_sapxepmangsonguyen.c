//
// Created by Admin on 16/06/2025.
//
#include <stdio.h>

int main() {
    int arr[] = {1, 7, 3, 5, 6, 4, 2, 10, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n -1; i++) {
        int temp;
        for (int j = 0; j < n -i -1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[i];
                arr[i] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// độ phức tạp về thời gian của trương trình sấp xỉ O(n^2)
// độ phức tạp về không gian của trương trình O(n)