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
    int index_with_edit;
    scanf("%d",&index_with_edit);
    if (index_with_edit < 0 || index_with_edit > 100) {
        printf("vuot qua so luong cho phep");
        return 3;
    }
    int number_edit;
    scanf("%d",&number_edit);
    if (number_edit <0 || number_edit > 1000) {
        printf("vuot qua so luong cho phep");
        return 2;
    }
    memoryPtr[index_with_edit] = number_edit;
    for (int i = 0; i < memory; i++) {
        printf("%d ",memoryPtr[i]);
    }
    return 0;
}