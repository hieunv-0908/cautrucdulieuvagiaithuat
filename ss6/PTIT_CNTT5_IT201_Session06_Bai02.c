//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

void print_fbnc(int number,int *arr,int len,int left,int number1,int number2);

int main() {
    int number;
    if (number ==0 || number <0) {
        return 0;
    }
    scanf("%d",&number);
    int *arr = malloc(number*sizeof(int));
    int number1=0;
    int number2=1;
    print_fbnc(number,arr,number,0,number1,number2);
    for(int i=number-1;i>=0;i--) {
        printf("%d ",arr[i]);
    }

    return 0;
}

void print_fbnc(int number,int *arr,int len,int left,int number1,int number2) {
    int temp=number1;
    if (left >= len) return;
        arr[left]=number1;
        arr[left+1]=number2;
        number1 =number2;
        number2 = temp+number2;
        return print_fbnc(number,arr,len,left+1,number1,number2);
}