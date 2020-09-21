#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode{ //单链表结构体定义
    int data;
    struct LinkNode* next;
}LinkNode;

typedef struct{  //链式队列结构体定义
    LinkNode* rear;
    LinkNode* front;
}LiQueue;

void InitQueue(LiQueue* queue){//无头结点队列初始化
    queue->rear=NULL;
    queue->front=NULL;
}

int EnQueue(LiQueue* queue,int e){
    LinkNode* p = (LinkNode*) malloc(sizeof(LinkNode));
    if(p==NULL) return 0;
    p->data=e;
    p->next=NULL;
    if(queue->rear==NULL) {
       queue->rear=queue->front=p;
    }
    else {
        queue->rear->next=p;
        queue->rear=p;
    }
    return 1;
}

int DeQueue(LiQueue* queue,int* e) {
    if(queue->front==NULL) return 0;
    LinkNode* p = queue->front;
    *e=p->data;
    queue->front=p->next;
    if(p==queue->rear) { //如果是最后一个元素删除
        queue->front=NULL;
        queue->rear=NULL;
    }
    free(p);
    return 1;
}

/*void InitQueue(LiQueue* queue){ //有头节点队列初始化
    queue->rear=queue->front=(LinkNode*) malloc(sizeof(LinkNode));
    if(queue->front==NULL) return;
    queue->front->next=NULL;
}
int IsEmpty(LiQueue queue){
    if(queue.front->next==NULL) return 1;
    else return 0;
}

int EnQueue(LiQueue* queue,int e){
    LinkNode* p=(LinkNode*) malloc(sizeof(LinkNode));
    if(p==NULL) return 0;
    p->data=e;
    p->next=NULL;
    queue->rear->next=p;
    queue->rear=p;
    return 1;
}

int DeQueue(LiQueue* queue,int* e){
    if(queue->front->next==NULL) return 0;
    LinkNode* p = queue->front->next;
    *e=p->data;
    queue->front->next=p->next;
    if(queue->rear==p) queue->rear=queue->front; //如果是最后一个元素删除
    free(p);
    return 1;
}
*/

int main(){
    LiQueue queue;
    InitQueue(&queue);
    EnQueue(&queue,2);
    EnQueue(&queue,1);
    EnQueue(&queue,3);
    int e;
    DeQueue(&queue,&e);
    printf("%d",e);
    DeQueue(&queue,&e);
    printf("%d",e);
    DeQueue(&queue,&e);
    printf("%d",e);
    return 0;
}
