#include "../common.h"

void change_binary(int number,char residual[],int * left){
    if (number==0)return;
    residual[*left] = number%2;
    (*left)++;
    return change_binary(number/2,residual,left);
}

int main() {
    int number;
    scanf("%d", &number);
    char residual[20];
    int left=0;
    change_binary(number,residual,&left);
    for (int i = left-1; i >= 0; i--) {
        printf("%d",residual[i]);
    }

    return 0;
}
