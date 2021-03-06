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
    ArcNode *first;
}VNode;

typedef struct
{
    VNode adjList[MAXSIZE];
    int n, e;
}AGraph;

void Visit(VNode v){
    printf("%d", v.data);
}
int visit[MAXSIZE]={0};
/*DFS深度优先遍历用到visit数组来判断当前结点是否已经访问*/
void DFS(int v,AGraph g){
    visit[v] = 1;
    Visit(g.adjList[v]);
    ArcNode *p = g.adjList[v].first;
    while (p!=NULL)
    {
        if(visit[p->adjV]==0)
            DFS(p->adjV, g);
        p = p->next;
    } 
}

/*BFS广度优先遍历用到visit数组来判断当前结点是否已经访问*/
void BFS(int v,AGraph g){
    int queue[MAXSIZE];
    int front = 0, rear = 0;
    Visit(g.adjList[v]);
    visit[v] = 1;
    ArcNode *p;
    rear = (rear + 1) % MAXSIZE;
    queue[rear] = v;
    int j;
    while (front!=rear)
    {
        front = (front + 1) % MAXSIZE;
        j = queue[front];
        p = g.adjList[j].first;
        while (p!=NULL)
        {
            if(visit[p->adjV]==0){
                Visit(g.adjList[p->adjV]);
                visit[p->adjV] = 1;
                rear = (rear + 1) % MAXSIZE;
                queue[rear] = p->adjV;
            }
            p = p->next;
        }        
    }
}

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
}

void create(AGraph *g){
    g->e = g->n = 0;

    for (int i = 0; i < 5; i++)
    {
        g->adjList[i].data = i;
        g->adjList[i].first = NULL;
        g->n++;
    }
    insertE(g, 0, 1);
    insertE(g, 1, 3);
    insertE(g, 2, 3);
    insertE(g, 1, 2);
    insertE(g, 3, 4);
}

void DFSnonre(AGraph *g,int v){
    int stack[MAXSIZE];
    int top = -1;
    int visited[g->n];

    for (int i = 0; i < g->n; i++)
        visited[i] = 0;

    ArcNode *p;
    stack[++top] = v;
    visited[v] = 1;
    Visit(g->adjList[v]);

    int now;
    while(top!=-1)
    {
        now = stack[top];
        p = g->adjList[now].first;
        while (p != NULL && visited[p->adjV] == 1)
            p = p->next;
        
        if(p==NULL)
            top--;
        else {
            Visit(g->adjList[p->adjV]);
            visited[p->adjV] = 1;
            stack[++top] = p->adjV;
        }
    }  

}

int main(){
    AGraph g;
    create(&g);
    DFS(0, g);
    printf("\n");
    DFSnonre(&g, 0);
    //BFS(0, g);
    return 0;
}
