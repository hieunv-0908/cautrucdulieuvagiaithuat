
#include "../common.h"

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
    int total = 0;
   for (int i = 0; i < memory; i++) {
       if (memoryPtr[i] %  2 == 0) {
           total += memoryPtr[i];
       }
   }
    printf("%d",total);
    free(memoryPtr);
    return 0;
}