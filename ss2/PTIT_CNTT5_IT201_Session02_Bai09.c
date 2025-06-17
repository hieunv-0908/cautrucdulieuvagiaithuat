//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int main() {
    int memory ;
    int number_max;
    int count_max=0;
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
        int count_max_temp=0;
        for (int j = i ; j < memory ; j++) {
            if (memoryPtr[i] == memoryPtr[j]) {
                count_max_temp++;
            }
        }
        if (count_max_temp > count_max) {
            count_max = count_max_temp;
            number_max = memoryPtr[i];
        }
    }
    printf("%d\n%d\n",number_max,count_max);
    free(memoryPtr);
}