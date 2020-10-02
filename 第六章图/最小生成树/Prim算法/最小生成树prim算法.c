#include<stdio.h>
#include<stdlib.h>
#include<float.h>

void create(int n,float g[][n]){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = FLT_MAX;
    g[0][1] = g[1][0] = 1;
    g[0][2] = g[2][0] = 2;
    g[0][3] = g[3][0] = 3;
    g[1][2] = g[2][1] = 7;
    g[1][4] = g[4][1] = 8;
    g[2][3] = g[3][2] = 6;
    g[2][4] = g[4][2] = 4;
    g[3][5] = g[5][3] = 5;
    g[4][5] = g[5][4] = 9;
}

/*prim算法形成最小生成树*/
void Prim(int n,float MGraph[][n],int v0,float *sum){
    float lowCost[n], vSet[n];
    int v, k;
    float min;
    for (int i = 0; i < n; i++)
    {
        lowCost[i] = MGraph[v0][i];
        vSet[i] = 0;
    }
    v = v0;
    vSet[v] = 1;
    *sum = 0;
    for (int i = 0; i < n-1; i++)
    {
        min = FLT_MAX;
        for (int j = 0; j < n; j++)
            if(vSet[j]==0&&lowCost[j]<min){
                min = lowCost[j];
                k = j;
            }
        vSet[k] = 1;
        *sum += min;
        v = k;
        for (int j = 0; j < n; j++)
            if(vSet[j]==0&&MGraph[v][j]<lowCost[j])
                lowCost[j] = MGraph[v][j];
    }
    
}

int main(){
    float graph[6][6];
    create(6,graph);
    float sum;
    Prim(6, graph, 0, &sum);
    printf("最小生成树的带权路径长度为%.2f", sum);
    return 0;
}