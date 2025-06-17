//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int main() {
    int memory ;
    int number1=0;
    int number2=0;
    int count;
    scanf("%d",&memory);
    if (memory <=0 || memory > 100) {
        printf("vuot qua so luong cho phep");
        return 1;
    }
    int *memoryPtr = (int*)malloc(memory*sizeof(int));
    for (int i = 0; i < memory; i++) {
        scanf("%d",&memoryPtr[i]);
        if (memoryPtr[i] <= 0 || memoryPtr[i] > 1000) {
            return 1;
        }
    }
    for (int i = 0 ; i < memory ; i++) {
        count =1;
        for (int j = i+1; j < memory ; j++) {
            if(memoryPtr[i] < memoryPtr[j]) {
                count =0;
                break;
            }
        }

        if (count == 1) {
            printf("%d  ",memoryPtr[i]);
        }

    }
    free(memoryPtr);
}