#include "../common.h"

void print_number(int number,int *number_taget);

int main() {
    int number_taget;
    scanf("%d",&number_taget);
    if (number_taget<0) {
        printf("lỗi");
        return 1;
    }
    while (getchar()!='\n');
    int number=number_taget-1;
    print_number(number,&number_taget);
    printf("%d",number_taget);
    return 0;
}

void print_number(int number,int *number_taget) {
    if (number > 0) {
        *number_taget *= number;
        return print_number(number-1,number_taget);
    }
}