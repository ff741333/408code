#include<stdio.h>
#include<stdlib.h>
#define MAXINF 10000
#define MAXSIZE 15

void create(int n,int g[][n]){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if(i!=j)
                g[i][j] = MAXINF;
            else
                g[i][j] = 0;
        }
    g[0][1] = 4;
    g[0][2] = 6;
    g[0][3] = 6;
    g[1][2] = 1;
    g[1][4] = 7;
    g[2][4] = 6;
    g[2][5] = 4;
    g[3][2] = 2;
    g[3][5] = 5;
    g[4][6] = 6;
    g[5][4] = 1;
    g[5][6] = 8;
}

//!!!nb
void Floyd(int n,int MGraph[][n],int path[][n]){
    int A[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            A[i][j] = MGraph[i][j];
            path[i][j] = -1;
        }
    for (int v = 0; v < n; v++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(A[i][v]+A[v][j]<A[i][j]&&i!=v&&i!=j&&j!=v){
                    A[i][j] = A[i][v] + A[v][j];
                    path[i][j] = v;
                }

}

void printPath(int u,int v,int path[][7]){
    if(path[u][v]==-1)
        printf("%d-%d ", u, v);
    else
    {
        int mid = path[u][v];
        printPath(u, mid, path);
        printPath(mid, v, path);
    }
}

int main(){
    int g[7][7];
    create(7, g);
    int path[7][7];
    Floyd(7, g, path);
    printPath(0, 4, path);
    return 0;   

}