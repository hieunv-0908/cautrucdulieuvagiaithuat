//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int str_symmetry(int left, int right,char str[100],int check);

int main() {
    char str[100];
    fgets(str,100,stdin);
    str[strlen(str)-1]='\0';
    int left =0;
    int right=strlen(str)-1;
    int check=1;
    check = str_symmetry(left,right,str,check);
    if (!check) {
        printf("Palindrome invalid");
    }else {
        printf("Palindrome");
    }

    return 0;
}

int str_symmetry(int left, int right,char str[100],int check) {
    if (!check) {
        return check;
    }
    if (left <= right) {
        if (str[left] == str[right] && str[left] != ' ' || str[right] != ' ') {
            return str_symmetry(left+1,right-1,str,check);
        }else {
            check =0;
            return str_symmetry(left+1,right-1,str,check);
        }
    }
}