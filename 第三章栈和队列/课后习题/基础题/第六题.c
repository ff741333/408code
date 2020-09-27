//假设以带头节点的循环链表表示队列，并且只设一个指针指向队尾结点，但不设头指针，请写出相应的入队列和出队列算法
#include<stdio.h>
typedef struct Node
{
    int data;
    struct Node *next;
}LNode;

typedef struct 
{
    LNode *rear;
}Queue;

int EnQueue(Queue q,int e){
    LNode *p = (LNode*)malloc(sizeof(LNode));
    if(p==NULL)
        return 0;
    p->data = e;
    p->next = q.rear->next;
    q.rear->next = p;
    return 1;
}

int DeQueue(Queue q,int *e){
    if(q.rear==q.rear->next)
        return 0;
    LNode *p = q.rear->next->next;
    *e = p->data;
    q.rear->next->next = p->next;
    if(p=q.rear)
        q.rear = q.rear->next;
    free(p);
    return 1;
}