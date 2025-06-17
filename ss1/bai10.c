//
// Created by Admin on 17/06/2025.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100];
    char str2[100];
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';
    int count = 0;
    if (strlen(str1) == strlen(str2)) {
        for (int i=0; i < strlen(str1) ; i++) {
            for (int j=0; j < strlen(str2); j++) {
               if (str1[i] == str2[j]) {
                   count++;
               }
            }
        }
    }else {
        printf("Khong phai chuoi hoan vi");
    }
    if (count == strlen(str1)) {
        printf("La chuoi hoan vi");
    }else {
        printf("Khong la chuoi hoan vi");
    }
    return 0;
}