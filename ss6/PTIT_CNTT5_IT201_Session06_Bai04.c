//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

void thaphanoi(int n , char A,char B , char C) {
    if (n == 1) {
        printf("Chuyen dia %d tu %c sang %c \n",n,A,C);
        return;
    }
    thaphanoi(n-1,A,C,B);
    printf("Chuyen dia %d tu %c sang %c \n",n,A,C);
    thaphanoi(n-1,B,A,C);

}


int main() {
    int n;
    printf("Enter n please:\n");
    scanf("%d", &n);
    if (n<=0) {
        return 1;
    }
    thaphanoi(n,'A','B','C');

    return 0;
}
