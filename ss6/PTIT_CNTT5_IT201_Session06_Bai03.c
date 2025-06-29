#include "../common.h"

int total_number(int number);

int main() {
    int number;
    scanf("%d",&number);
    if (number < 0)return 0;
    int tong = total_number(number);
    printf("%d",tong);


}

int total_number(int number) {
    if (number == 0)return 0;

    return number %10 + total_number(number/10);
}