#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 15

typedef struct 
{
    int a, b;
    int w;//权重
}Road;

int getRoot(int p,int v[]){
    while (p!=v[p])
        p = v[p];
    return p;
}

/*将road根据权重w排序*/
void sort(Road road[],int n){
    Road temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n-1; j++)
        {
            if(road[j].w>road[j+1].w){
                temp = road[j];
                road[j] = road[j + 1];
                road[j + 1] = temp;
            }
        }
}

void Kruskal(Road road[],int n,int e,int *sum){
    int a, b;
    int v[MAXSIZE];
    *sum = 0;
    for (int i = 0; i < n; i++)
        v[i] = i;
    sort(road,e);
    for (int i = 0; i < e; i++)
    {
        a = getRoot(road[i].a, v);
        b = getRoot(road[i].b, v);
        if(a!=b){
            v[a] = b;
            *sum += road[i].w;
        }
    }
}

void insert(Road road[],int i,int a,int b,int w){
    road[i].a = a;
    road[i].b = b;
    road[i].w = w;
}

void create(Road road[]){
    insert(road, 0, 0, 1, 1);
    insert(road, 1, 0, 2, 5);
    insert(road, 2, 0, 3, 6);
    insert(road, 3, 1, 2, 8);
    insert(road, 4, 2, 3, 7);   
    insert(road, 5, 1, 4, 4);
    insert(road, 6, 2, 4, 2);
    insert(road, 7, 4, 5, 9);
    insert(road, 8, 3, 5, 3);
}
int main(){
    Road road[MAXSIZE];
    create(road);
    int sum;
    Kruskal(road, 6, 9, &sum);
    printf("%d", sum);

    return 0;
}
