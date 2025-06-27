#include <stdio.h>

int countPaths(int row, int col) {
    if (row == 1 || col == 1) return 1;

    return countPaths(row - 1, col) + countPaths(row, col - 1);
}

int main() {
    int m, n;
    printf("Nhap so hang: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);

    if (m <= 0 || n <= 0) {
        printf("Kich thuoc khong hop le.\n");
        return 1;
    }

    int result = countPaths(m, n);
    printf("So duong di tu (0,0) den (%d,%d): %d\n", m - 1, n - 1, result);
    return 0;
}
