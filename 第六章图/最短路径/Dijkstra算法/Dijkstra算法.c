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

void Dijkstra(int n,int MGraph[][n],int v0,int dist[],int path[]){
    int set[MAXSIZE];
    int min, v;
    for (int i = 0; i < n; i++)
    {
        dist[i] = MGraph[v0][i];
        set[i] = 0;
        if(MGraph[v0][i]<MAXINF)
            path[i] = 0;
        else
            path[i] = -1;
    }
    set[v0] = 1;
    path[v0] = -1;
    for (int i = 0; i < n-1; i++)
    {
        min = MAXINF;
        for (int j = 0; j < n; j++)
            if(set[j]==0&&dist[j]<min){
                v = j;
                min = dist[j];
            }
        set[v]=1;
        for (int j = 0; j < n; j++)
        {
            if(set[j]==0&&dist[v]+MGraph[v][j]<dist[j]){
                dist[j] = dist[v] + MGraph[v][j];
                path[j] = v;
            }
        }            
    }  
}

int main(){
    int g[7][7];
    create(7, g);
    int dist[7], path[7];

    Dijkstra(7, g, 0, dist, path);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", path[i]);
    }
    
    return 0;
}