#include<stdio.h>
#define MAXSIZE 20

typedef struct LNode
{
    int data[MAXSIZE];
    int front;
    int rear;
}Queue;

int RearDe(Queue *q,int *e){
    if(q->rear=q->front)
        return 0;

    if(q->rear==0)
        q->rear = MAXSIZE - 1;
    else
        q->rear--;
    *e = q->data[q->rear];
    return 1;
}

int FrontEn(Queue *q,int e){
    if((q->rear+1)%MAXSIZE==q->front)
        return 0;
    if(q->front==0)
        q->front = MAXSIZE;
    else
        q->front--;
    q->data[q->front] = e;
    return 1;
}