#include "../common.h"

void print_number(int number,int number_taget,int *total);

int main() {
    int total=0;
    int number_taget;
    int number=1;
    scanf("%d",&number_taget);
    while (getchar()!='\n');
    print_number(number,number_taget,&total);
    printf("%d ",total);
    return 0;
}

void print_number(int number,int number_taget,int *total) {
    if (number <= number_taget) {
        *total+=number;
        number++;
        return print_number(number,number_taget,total);
    }
}