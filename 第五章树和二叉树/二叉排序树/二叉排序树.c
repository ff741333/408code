#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
//二叉树的链式存储
typedef struct BiTNode
{
    int data;
    int high;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

void create(BiTree *t,int list[],int len){
    if(len<=0)
        return;
    int i = 0;
    if(*t==NULL){
        *t = (BiTNode *)malloc(sizeof(BiTNode));
        (*t)->data = list[i++];
        (*t)->lchild = (*t)->rchild = NULL;
    }
    BiTNode *p,*q;
    for (; i < len; i++)
    {
        q = NULL;
        p = *t;
        while (p!=NULL)
        {
            if(list[i]<p->data){
                if(p->lchild==NULL){
                    q = (BiTNode *)malloc(sizeof(BiTNode));
                    q->data = list[i];
                    q->lchild = q->rchild = NULL;
                    p->lchild = q;
                    break;
                }
                p = p->lchild;
            }
            else {
                if(p->rchild==NULL){
                    q = (BiTNode *)malloc(sizeof(BiTNode));
                    q->data = list[i];
                    q->lchild = q->rchild = NULL;
                    p->rchild = q;
                    break;
                }
                p = p->rchild;
            }
        }
        
    }  
}

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

int sethigh(BiTree t){
    if(t==NULL)
        return 1;
    int lhigh, rhigh;
    lhigh = sethigh(t->lchild);
    rhigh = sethigh(t->rchild);
    if(lhigh>rhigh){
        t->high = lhigh;
        return lhigh+1;
    }
    else{
        t->high = rhigh;
        return rhigh+1;
    }
}

int main(){
    int list[] = {4, 5, 4, 7, 2, 6, 7, 8, 9};
    BiTree t=NULL;
    create(&t, list, 9);
    sethigh(t);
    InOrder(t);
    return 0;
}