//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

void total_number(int *number,int number_taget1,int number_taget2);

int main() {
    int number=0;
    int number_taget1;
    int number_taget2;
    scanf("%d",&number_taget1);
    scanf("%d",&number_taget2);
    if (number_taget1<0||number_taget2<0) {
        return 0;
    }
    while (getchar()!='\n');
    total_number(&number,number_taget1,number_taget2);
    return 0;
}

void total_number(int *number,int number_taget1,int number_taget2) {
    if (number_taget1<=number_taget2) {
        *number+=number_taget1;
        number_taget1++;
        return total_number(number,number_taget1,number_taget2);
    }
    printf("%d",*number);
}