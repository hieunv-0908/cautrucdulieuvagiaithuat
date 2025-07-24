//
// Created by Admin on 24/07/2025.
//
#include "../common.h"

void add_edge(int matrix[][100],int u,int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void display_matrix(int matrix[][100],int n) {
    for (int i=0; i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void dfs(int matrix[][100],bool visit[200]) {

}

int main(){
    int matrix[100][100] = {0};
    bool visit[200];
    add_edge(matrix,0,1);
    add_edge(matrix,0,2);
    add_edge(matrix,1,2);
    add_edge(matrix,3,2);
    add_edge(matrix,1,3);
    add_edge(matrix,3,4);
    display_matrix(matrix,6);
}