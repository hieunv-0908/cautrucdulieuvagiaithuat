//
// Created by Admin on 17/06/2025.
//
#include "../common.h"



int main() {
    char str[100];
    fgets(str,100,stdin);
    printf("%s",str);
    str[strlen(str)-1]='\0';
    char temp;
    for (int i = 0; i < strlen(str)-2; i++) {
        for (int j = i+1; j < strlen(str)-i-2; j++) {
            if (str[j]>str[j+1]) {
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
    printf("%s",str);
    return 0;
}
