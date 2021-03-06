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

int getIn(AGraph g,int k){
    ArcNode *p;
    int count = 0;
    for (int i = 0; i < g.n; i++)
    {
        p = g.adjList[i].first;
        while (p!=NULL){
            if(p->adjV==k){
                count++;
                break;
            }
            p = p->next;
        }
 
    }
    return count;
}

int main(){
    AGraph g;
    create(&g);
    //DFS(0, g);

    printf("%d",getIn(g, 0));
    //BFS(0, g);
    return 0;
}
