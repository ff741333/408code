#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
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
    printf("%c", node->data);
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

/*非递归先序遍历*/
void preorderNonrecursion(BiTree t){
    if(t!=NULL){
        BiTNode *stack[MAXSIZE];
        int top = -1;
        BiTNode *p = NULL;
        stack[++top] = t;
        while (top!=-1)
        {
            p = stack[top--];
            visit(p);
            if(p->rchild!=NULL)
                stack[++top] = p->rchild;
            if(p->lchild!=NULL)
                stack[++top] = p->lchild;
        }        
    }
}
/*后序非递归遍历*/
void postorderNonrecursion(BiTree t){
    if(t!=NULL){
        BiTNode *stack1[MAXSIZE];
        BiTNode *stack2[MAXSIZE];
        int top1 = -1;
        int top2 = -1;
        BiTNode *p = NULL;
        stack1[++top1] = t;
        while (top1!=-1)
        {
            p = stack1[top1--];
            stack2[++top2] = p;
            if(p->lchild!=NULL)
                stack1[++top1] = p->lchild;
            if(p->rchild!=NULL)
                stack1[++top1] = p->rchild;
        }
        while (top2!=-1)
        {
            visit(stack2[top2--]);
        }      
    }
}
/*非递归中序遍历*/
void inorderNonrecursion(BiTree t){
    if(t!=NULL){
        BiTNode *stack[MAXSIZE];
        BiTNode *p = NULL;
        int top = -1;
        p = t;
        while (top!=-1||p!=NULL)
        {
            while (p!=NULL)
            {
                stack[++top] = p;
                p = p->lchild;
            }
            if(top!=-1){
                p = stack[top--];
                visit(p);
                p = p->rchild;
            }
        }
        
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

/*根据前序和中序构造二叉树*/
BiTNode *picreate(char pre[],char in[],int l1,int r1,int l2,int r2){
    if(l1>r1)
        return NULL;
    BiTNode *s = (BiTNode *)malloc(sizeof(BiTNode));
    s->lchild = s->rchild = NULL;
    s->data = pre[l1];

    int i;
    for ( i = l2; i <= r2; i++)
    {
        if(pre[l1]==in[i])
            break;
    }
    s->lchild = picreate(pre, in, l1 + 1, l1 + i - l2, l2, i - 1);
    s->rchild = picreate(pre, in, l1 + i - l2 + 1, r1, i + 1, r2);
    return s;
}

/*根据后序和中序构造二叉树*/
BiTNode *poicreate(char post[],char in[],int l1,int r1,int l2,int r2){
    if(l1>r1)
        return NULL;
    BiTNode *s = (BiTNode *)malloc(sizeof(BiTNode));
    s->data = post[r1];
    s->lchild = s->rchild = NULL;
    int i;

    for (i = l2; i <= r2;i++){
        if(post[r1]==in[i])
            break;
    }
    s->lchild = poicreate(post, in, l1, l1 + i - l2 - 1, l2, i - 1);
    s->rchild = poicreate(post, in, l1 + i - l2 , r1 - 1, i + 1, r2);
    return s;
}

int main(){
    BiTree t;
    /*create(&t);
    InOrder(t);
    printf("\n");
    inorderNonrecursion(t);
    printf("\n");
    PreOrder(t);
    printf("\n");
    preorderNonrecursion(t);
    printf("\n");
    PostOrder(t);
    printf("\n");
    postorderNonrecursion(t);
    */
    char post[] = {'4', '5', '2', '6', '7', '3', '1'};
    char pre[] = {'1', '2', '4', '5', '3', '6', '7'};
    char in[] = {'4', '2', '5', '1', '6', '3', '7'};
    //t=picreate(pre, in, 0, 6, 0, 6);
    t = poicreate(post, in, 0, 6, 0, 6);
    InOrder(t);
    printf("\n");
    PreOrder(t);
    return 0;
}