//
// Created by Admin on 17/06/2025.
//
#include "../../common.h"

int main() {
    int memory ;
    int number1=0;
    int number2=0;
    int taget;
    int count;
    scanf("%d",&taget);
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
        count =0;
        for (int j = i+1; j < memory ; j++) {
            if (memoryPtr[i] + memoryPtr[j] == taget && memoryPtr[i] != memoryPtr[j]) {
                number1 = memoryPtr[i];
                number2 = memoryPtr[j];
                i++;
                count++;
                break;
            }
        }
        if (!count) {
            printf("so %d khong tim duoc cap \n",memoryPtr[i]);
        }else {
            printf("%d va %d la mot cap co tong bang taget \n",number1,number2);
        }
    }
    free(memoryPtr);
}