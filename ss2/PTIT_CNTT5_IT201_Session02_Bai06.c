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
    for (int i = 0; i < memory; i++) {
        scanf("%d",&memoryPtr[i]);
    }
    int index_with_insert;
    scanf("%d",&index_with_insert);
    int number_with_insert;
    scanf("%d",&number_with_insert);
    for (int i = memory-1 ; i > 0 ; i--) {
        memoryPtr[i+1] = memoryPtr[i];
    }
    memoryPtr[index_with_insert] = number_with_insert;
    memory +=1;
    for (int i = 0; i < memory; i++) {
        printf("%d ",memoryPtr[i]);
    }
}