#include<stdio.h>
#include<stdlib.h>
//二叉树的链式存储
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

typedef struct LinkNode{ //单链表结构体定义
    BiTNode *data;
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

int EnQueue(LiQueue* queue,BiTNode *e){
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

int DeQueue(LiQueue* queue,BiTNode **e) {
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


/*//二叉树的顺序存储，初始化是要将isEmpty设为1，占用空间大，一般不用
#define MAXSIZE 100
struct TreeNode
{
    int value;
    int isEmpty;
}TreeNode;
TreeNode t[MAXSIZE];
*/



void visit(BiTNode *node){
    printf("%d", node->data);
}

/*中序遍历*/
void InOrder(BiTree t){
    if(t!=NULL) {
        InOrder(t->lchild);
        visit(t);
        InOrder(t->rchild);
    }
}

/*前序遍历*/
void PreOrder(BiTree t){
    if(t!=NULL) {
        visit(t);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}


/*后序遍历*/
void PostOrder(BiTree t){
    if(t!=NULL) {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        visit(t);
    }
}

/*通过队列构造一个树*/
void create(BiTree *t){
    *t = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->data = 1;
    LiQueue q;
    InitQueue(&q);
    EnQueue(&q, *t);
    int i=2;
    BiTNode *p;
    while (i<7)
    {
        DeQueue(&q, &p);
        BiTNode *l = (BiTNode *)malloc(sizeof(BiTNode));
        BiTNode *r = (BiTNode *)malloc(sizeof(BiTNode));
        l->data = i;
        ++i;
        r->data = i;
        ++i;
        l->lchild = l->rchild = r->lchild = r->rchild = NULL;
        p->lchild = l;
        p->rchild = r;
        EnQueue(&q, l);
        EnQueue(&q, r);
    } 
}

int main(){
    BiTree t;
    create(&t);
    InOrder(t);
    printf("\n");
    PreOrder(t);
    printf("\n");
    PostOrder(t);
    return 0;
}