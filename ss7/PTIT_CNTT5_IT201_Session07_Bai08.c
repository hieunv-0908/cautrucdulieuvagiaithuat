//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int total_cach(int n);

int main() {
    int n;
    printf("moi nhap vao so bac:");
    scanf("%d",&n);
    while (getchar()!='\n');
    printf("%d cach",total_cach(n));
    return 0;
}

int total_cach(int n) {
    if (n == 0) return 1;
    if (n<0) return 0;
    return total_cach(n-1) + total_cach(n-2);

}