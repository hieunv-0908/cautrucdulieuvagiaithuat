#include "../../common.h"

int main() {
    int memory ;
    scanf("%d",&memory);
    if (memory <=0 || memory > 100) {
        return 1;
    }
    int *memoryPtr = (int*)malloc(memory*sizeof(int));
    for (int i = 0; i < memory; i++) {
        scanf("%d",&memoryPtr[i]);
    }
    int maxNumber = memoryPtr[0];
    for (int i = 1; i < memory; i++) {
        if (memoryPtr[i] > maxNumber) {
            maxNumber = memoryPtr[i];
        }
    }
    printf("%d\n",maxNumber);


    return 0;
}