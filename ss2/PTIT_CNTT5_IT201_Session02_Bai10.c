//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int main() {
    int memory;
    int number;
    int count;
    scanf("%d",&memory);
    if (memory <=0 || memory > 100) {
        printf("vuot qua so luong cho phep");
        return 1;
    }
    int *memoryPtr = (int*)malloc(memory * sizeof(int));
    int flag[1001]={0};
    for (int i = 0; i < memory; i++) {
        scanf("%d",&memoryPtr[i]);
        if (memoryPtr[i] <= 0 || memoryPtr[i] > 1000) {
            return 1;
        }
    }
    for (int i = 0; i < memory; i++) {
        count =0;
        if (flag[memoryPtr[i]]) {
            continue;
        }
        flag[memoryPtr[i]] = 1;
        for (int j = 0; j < memory; j++) {
            if (memoryPtr[i] == memoryPtr[j]) {
                count++;
            }
        }
        printf("so %d xuat hien %d \n",memoryPtr[i],count);
    }
    free(memoryPtr);

    return 0;
}