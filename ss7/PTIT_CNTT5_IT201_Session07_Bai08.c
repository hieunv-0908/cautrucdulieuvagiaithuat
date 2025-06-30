#include <stdio.h>

int main() {
    int rows, cols;
    printf("rows = ");
    scanf("%d", &rows);
    printf("cols = ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("Kích thước mảng không hợp lệ\n");
        return 1;
    }

    int arr[1000][1000];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int k;
    printf("k = ");
    scanf("%d", &k);

    if (k < 0 || k >= cols) {
        printf("Chỉ số cột không hợp lệ\n");
        return 1;
    }

    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (arr[i][k] > arr[j][k]) {
                for (int col = 0; col < cols; col++) {
                    int temp = arr[i][col];
                    arr[i][col] = arr[j][col];
                    arr[j][col] = temp;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
