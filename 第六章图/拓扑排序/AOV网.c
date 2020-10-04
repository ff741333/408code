#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 15

typedef struct ArcNode
{
    int adjV;
    struct ArcNode *next;
}ArcNode;

typedef struct
{
    int data;
    int count;
    ArcNode *first;
}VNode;

typedef struct
{
    VNode adjList[MAXSIZE];
    int n, e;
}AGraph;

/*创建边结点*/
void insertE(AGraph *g,int start,int end){
    ArcNode *p = g->adjList[start].first;
    if(p==NULL){
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjV = end;
        p->next = NULL;
        g->adjList[start].first = p;
    }
    else {
        while (p->next!=NULL)
        {
            p = p->next;
        }
        ArcNode *q = (ArcNode *)malloc(sizeof(ArcNode));
        q->adjV = end;
        q->next = NULL;
        p->next = q;
    }
    g->e++;
    g->adjList[end].count++;
}

void create(AGraph *g){
    g->e = g->n = 0;

    for (int i = 0; i < 5; i++)
    {
        g->adjList[i].data = i;
        g->adjList[i].count = 0;
        g->adjList[i].first = NULL;
        g->n++;
    }
    insertE(g, 0, 1);
    insertE(g, 0, 2);
    insertE(g, 2, 3);
    insertE(g, 1, 3);
    insertE(g, 3, 4);
}

void TopSort(AGraph *g){
    int i, j, n = 0;
    int stack[MAXSIZE], top = -1;
    ArcNode *p;
    
    for (i = 0; i < g->n; i++)
        if(g->adjList[i].count==0)
            stack[++top] = i;
    
    while (top!=-1)
    {
        i = stack[top--];
        ++n;
        printf("%d ", i);

        p = g->adjList[i].first;
        while (p!=NULL)
        {
            j = p->adjV;
            g->adjList[j].count--;
            if(g->adjList[j].count==0)
                stack[++top] = j;
            p = p->next;
        }        
    }   
}

int visit[MAXSIZE]={0};
void DFS(int v,AGraph *g){
    ArcNode *p = g->adjList[v].first;
    visit[v] = 1;

    while (p!=NULL)
    {
        if(visit[p->adjV]==0)
            DFS(p->adjV, g);
        p = p->next;
    }
    printf("%d ", g->adjList[v].data);
}

int main(){
    AGraph g;
    create(&g);
    TopSort(&g);
    printf("\n");
    DFS(0, &g);
    return 0;
}

