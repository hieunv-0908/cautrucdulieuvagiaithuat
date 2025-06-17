//
// Created by Admin on 17/06/2025.
//
#include "../../common.h"

int main() {
    int memory ;
    scanf("%d",&memory);
    if (memory <=0 || memory > 100) {
        printf("vuot qua so luong cho phep");
        return 1;
    }
    int *memoryPtr = (int*)malloc(memory*sizeof(int));
    int *memoryPtr2 = (int*)malloc(memory*sizeof(int));
    for (int i = 0; i < memory; i++) {
        scanf("%d",&memoryPtr[i]);
    }
    for (int i = 0; i < memory; i++) {
        memoryPtr2[i] = memoryPtr[memory -i -1];
    }
    for (int i = 0; i < memory; i++) {
        printf("%d ",memoryPtr2[i]);
    }
}