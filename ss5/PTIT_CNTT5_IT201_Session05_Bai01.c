#include "../common.h"

int print_number(int number,int number_taget);

int main() {
    int number_taget;
    int number=1;
    scanf("%d",&number_taget);
    while (getchar()!='\n');
    print_number(number,number_taget);
    return 0;
}

int print_number(int number,int number_taget) {

    if (number<= number_taget) {
        printf("%d ",number);
        number++;
        return print_number(number,number_taget);
    }
    return 0;
}