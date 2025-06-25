#include "../common.h"

int main() {
    int memory ;
    scanf("%d",&memory);
    if (memory <=0) {
        printf("so luong khong duoc am");
        return 1;
    }else if(memory>100){
        printf("so luong khong duoc quas 100");
    }
    int *memoryPtr = (int*)malloc(memory*sizeof(int));
    for (int i = 0; i < memory; i++) {
        scanf("%d",&memoryPtr[i]);
    }
    for (int i = 0; i < memory; i++) {
        printf("%d ",memoryPtr[i]);
    }
free(memoryPtr);
return 0;
}