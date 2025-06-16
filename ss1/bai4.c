#include <stdio.h>
#include <stdlib.h>

int main() {

}

void totalC1() {
    int n;
    int total = 0;
    for (int i=0; i<=n; i++) {
        total += i;
    }
    printf("total = %d\n", total);
    // độ phức tạp của cách 1 là O(1)
}

void totalC2() {
    int n;
    int total = (n*(n+1))/2;
    printf("total = %d\n", total);
    //độ phức tạp của cách 2 là O(1)
}
