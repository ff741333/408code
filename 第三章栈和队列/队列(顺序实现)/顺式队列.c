#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct{
    int data[MAXSIZE];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue* queue){
    queue->front=queue->rear=0; //将队头指针和队尾指针设为0
}

int IsEmpty(SqQueue queue){
    if(queue.front==queue.rear) return 1;
    else return 0;
}

int EnQueue(SqQueue* queue,int e){
    if((queue->rear+1)%MAXSIZE==queue->rear) return 0;
    queue->data[queue->rear]=e;
    queue->rear=(queue->rear+1)%MAXSIZE;
    return 1;
}

int DeQueue(SqQueue* queue,int* e){
    if(IsEmpty(*queue)) return 0;
    *e=queue->data[queue->front];
    queue->front=(queue->front+1)%MAXSIZE;
}

int GetHead(SqQueue queue,int* e){
    if(IsEmpty(queue)) return 0;
    *e=queue.data[queue.front];
    return 1;
}

int main(){
    SqQueue queue;
    InitQueue(&queue);
    EnQueue(&queue,1);
    int e;
    GetHead(queue,&e);
    printf("%d",e);
    return 0;
}
