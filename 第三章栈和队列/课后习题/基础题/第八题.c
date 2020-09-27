#include<stdio.h>
#define MAXSIZE 20

typedef struct 
{
    int data[MAXSIZE];
    int front;
    int rear;
    int tag;
}Queue;

void InitQueue(Queue *q){
    q->front = q->rear = q->tag = 0;
}

int EnQueue(Queue *q,int e){
    if(q->tag==1&&q->front==q->rear)
        return 0;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    q->tag = 1;
    return 1;
}

int DeQueue(Queue *q,int *e){
    if(q->tag==0&&q->front==q->rear)
        return 0;
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    if(q->front==q->rear)
        q->tag = 0;
    return 1;
}