    //
    // Created by Admin on 17/06/2025.
    //
    #include "../common.h"

    int bynarySearch(int *arr,int len,int left,int right,int number_search);

    void arrange(int *arr,int len);

    int main() {
        int memory;
        printf("Moi ban nhap vao so luong bo nho muon cap phat:");
        scanf("%d",&memory);
        while (getchar() != '\n');
        int *arr = (int*)malloc(memory*sizeof(int));
        int len;
        printf("moi nhap vao do dai cua mang:");
        scanf("%d",&len);
        while (getchar() != '\n');
        for (int i = 0; i < len; i++) {
            printf("arr[%d]:",i);
            scanf("%d",&arr[i]);
            while (getchar() != '\n');
        }
        int number_search;
        printf("nhap vao phan tu muon tim kiem:");
        scanf("%d",&number_search);
        while (getchar() != '\n');
        arrange(arr,len);
        int left=0;
        int right=len-1;
        int mid_search=bynarySearch(arr,len,left,right,number_search);
        if (!mid_search) {
            printf("khong tim thay phan tu trong mang");
        }else {
            printf("so can tim o vi tri so %d",mid_search);
        }

        free(arr);
        return 0;
    }

    void arrange(int *arr,int len) {
        int temp;
        for (int i = 0; i < len-1; i++) {
            for (int j = 0; j < len-i-1; j++) {
                if (arr[i]>arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    int bynarySearch(int *arr,int len,int left,int right,int number_search) {
        if (left > right) {
            return -1;
        }
        int mid = (left+right)/2;
            if (arr[mid] == number_search) {
                return mid;
            }else if (arr[mid] > number_search) {
                return bynarySearch(arr,len,left,mid-1,number_search);
            }else if (arr[mid] < number_search) {
                return bynarySearch(arr,len,mid+1,right,number_search);
            }
        return -1;
    }












































