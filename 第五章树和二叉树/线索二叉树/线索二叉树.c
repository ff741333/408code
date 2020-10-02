#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

typedef struct LinkNode{ //单链表结构体定义
    ThreadNode *data;
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

int EnQueue(LiQueue* queue,ThreadNode *e){
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

int DeQueue(LiQueue* queue,ThreadNode **e) {
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

/*通过队列构造一个树*/
void create(ThreadTree *t){
    *t = (ThreadNode *)malloc(sizeof(ThreadNode));
    (*t)->data = 1;
    (*t)->lchild = (*t)->rchild = NULL;
    (*t)->ltag = (*t)->rtag = 0;
    LiQueue q;
    InitQueue(&q);
    EnQueue(&q, *t);
    int i=2;
    ThreadNode *p;
    while (i<7)
    {
        DeQueue(&q, &p);
        ThreadNode *l = (ThreadNode *)malloc(sizeof(ThreadNode));
        ThreadNode *r = (ThreadNode *)malloc(sizeof(ThreadNode));
        l->data = i;
        ++i;
        r->data = i;
        ++i;
        l->lchild = l->rchild = r->lchild = r->rchild = NULL;
        l->ltag = l->rtag = r->ltag = r->rtag = 0;
        p->lchild = l;
        p->rchild = r;
        EnQueue(&q, l);
        EnQueue(&q, r);
    } 
}
/*全局变量，指向当前访问结点的前驱*/
ThreadNode *pre = NULL;
void visit(ThreadNode *node){
    if(node->lchild==NULL){
        node->lchild = pre;
        node->ltag = 1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild = node;
        pre->rtag = 1;
    }
    pre = node;
}
/*中序构造线索二叉树*/
void InThread(ThreadTree t){
    if(t!=NULL){
        InThread(t->lchild);
        visit(t);
        InThread(t->rchild);
    }
}
/*中序线索化二叉树*/
void CreateInThread(ThreadTree t){
    pre = NULL;
    if(t!=NULL){
        InThread(t);
        if(pre->rchild==NULL)
            pre->rtag = 1;
    }
}
/*寻找以node为根的子树中中序遍历的第一个结点*/
ThreadNode *Firstnode(ThreadNode *node){
    while(node->ltag==0)
        node = node->lchild;
    return node;
}
/*寻找中序遍历中node结点的后继结点*/
ThreadNode *NextNode(ThreadNode *node){
    if(node->rtag==0)
        return Firstnode(node->rchild);
    else
        return node->rchild;
}
/*中序遍历线索二叉树*/
void Inorder(ThreadTree t){
    for (ThreadNode *p = Firstnode(t); p != NULL;p=NextNode(p)){
        printf("%d ", p->data);
    }
}

ThreadNode *LastNode(ThreadNode *node){
    while(node->rtag==0)
        node = node->rchild;
    return node;
}
ThreadNode *PreNode(ThreadNode *node){
    if(node->ltag==0)
        return LastNode(node->lchild);
    else
        return node->lchild;
}
void RevInorder(ThreadTree t){
    for (ThreadNode *p = LastNode(t); p != NULL;p=PreNode(p)){
        printf("%d ",p->data);
    }
}
int main(){
    ThreadTree t;
    create(&t);
    CreateInThread(t);
    Inorder(t);
    printf("\n");
    RevInorder(t);
    return 0;
}