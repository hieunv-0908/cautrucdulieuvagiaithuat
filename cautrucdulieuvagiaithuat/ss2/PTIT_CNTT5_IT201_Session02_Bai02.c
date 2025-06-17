//
// Created by Admin on 17/06/2025.
//
#include "../../common.h"

int main() {
    int count =0;
    int taget;
    scanf("%d",&taget);
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
    for (int i = 0; i < memory; i++) {
        if (memoryPtr[i] == taget) {
            count++;
        }
    }
    if (!count) {
        printf("khong xuat hien trong mang");
    }else {
        printf("xuat hien %d lan",count);
    }
}