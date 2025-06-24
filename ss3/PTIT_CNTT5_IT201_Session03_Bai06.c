//
// Created by Admin on 17/06/2025.
//
#include "../common.h"

int main() {
   int n;
   printf("n=");
   scanf("%d",&n);
   if (n < 0 || n > 1000) {
      printf("so luong khong hop le\n");
      return 0;
   }
   int *arr = (int*)malloc(n * sizeof(int));
   if (arr == NULL) {
      return 1;
   }
   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   int m;
   printf("m=");
   scanf("%d", &m);
   int n_temp = n+m;
   if (n_temp == 0) {
      for (int i = 0; i < n; i++) {
         printf(" %d", arr[i]);
      }
      return 1;
   }else if (n_temp < 0) {
      return 1;
   }

   int *arr_temp = (int*)realloc(arr, n_temp*sizeof(int));
   if (arr_temp == NULL) {
      return 1;
   }
   arr = arr_temp;
   for (int i =n; i < n_temp; i++) {
      scanf("%d", &arr[i]);
   }
   n=n_temp;

   for (int i = 0; i < n; i++) {
      printf(" %d", arr[i]);
   }

   free(arr);

   return 0;
}