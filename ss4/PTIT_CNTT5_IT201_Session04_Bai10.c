//
// Created by Admin on 17/06/2025.
//
#include "../common.h"


void to_lower_str(int *str[100]) {
    for (int i=0; str[i] ;i++) {
        str[i] = tolower(str[i]);
    }
}
int main() {
    struct sinhvien {
        char *id;
        char *name;
        int age;
    };
    int len;
    int len_memory_sinhvien;
    printf("nhap vao so luong sinh vien muon cap phat:");
    scanf("%d",&len_memory_sinhvien);
    while(getchar()!='\n');
    struct sinhvien *dssv = (struct sinhvien *)malloc(len_memory_sinhvien*sizeof(struct sinhvien));
    if (dssv==NULL) {
        printf("cap phat that bai.");
        return 1;
    }
    printf("nhap so luong sinh vien muon them khong duoc vuot qua %d",len_memory_sinhvien);
    scanf("%d",&len);
    while (getchar()!='\n');
    if (len<0 || len>len_memory_sinhvien) {
        printf("so luong muon nhap da vuot qua bo nho cho phep");
        return 0;
    }else if (len==0) {
        printf("hay chac chan voi lua chon cua ban");
    }else {
        for (int i=0;i<len;i++) {
            dssv[i].id=(char *)malloc(100*sizeof(char));
            dssv[i].name=(char *)malloc(100*sizeof(char));
            printf("nhap ma sv%d ",i+1);
            fgets(dssv[i].id, 100, stdin);
            dssv[i].id[strcspn(dssv[i].id,"\n")]='\0';
            printf("nhap ten sv %d ",i+1);
            fgets(dssv[i].name, 100, stdin);
            dssv[i].name[strcspn(dssv[i].name,"\n")]='\0';
            printf("nhap tuoi sv%d ",i+1);
            scanf("%d",&dssv[i].age);
            while (getchar()!='\n');
        }
    }

    int check=0;
    printf("nhap ten can tim kiem ");
    char name_search[100];
    fgets(name_search,100,stdin);
    name_search[strcspn(name_search,"\n")]='\0';

    for (int i=0;i<len;i++) {
        int temp[100];
        strcpy(temp,dssv[i].name);
        to_lower_str(temp);
        if (strstr(temp,name_search)) {
            check=1;
            printf("ID:%s,NAME:%s,AGE:%d\n",dssv[i].id,dssv[i].name,dssv[i].age);
        }
    }

    if (!check) {
        printf("phan tu khong co trong mang");
    }
    free(dssv);
    for (int i=0;i<len;i++) {
        free(dssv[i].id);
        free(dssv[i].name);
    }

    return 0;
}