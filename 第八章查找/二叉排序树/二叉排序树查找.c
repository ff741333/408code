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

/*
BiTNode *BSTSearch(BiTree p,int key){
    while (p!=NULL)
    {

        if(key==p->data)
            return p;
        else if(key>p->data)
            p = p->rchild;
        else
            p = p->lchild;

    }
    return NULL;
}
*/

BiTNode *BSTSearch(BiTree t,int key){
    if(t==NULL)
        return NULL;
    if(key==t->data)
        return t;
    else if(key<t->data)
        return BSTSearch(t->lchild, key);
    else
        return BSTSearch(t->rchild, key);
}

int BSTInsert(BiTNode **p,int key){
    if(*p==NULL){
        *p = (BiTNode *)malloc(sizeof(BiTNode));
        (*p)->data = key;
        (*p)->lchild = (*p)->rchild = NULL;
        return 1;
    }
    else
    {
        if(key==(*p)->data)
            return 0;
        else if (key < (*p)->data)
            return BSTInsert(&(*p)->lchild, key);
        else
            return BSTInsert(&(*p)->rchild, key);
    }
    
}

void BSTDelete(BiTree *t,int key){
    if(t==NULL)
        return;
    if (key < (*t)->data)
        BSTDelete(&(*t)->lchild, key);
    else if (key > (*t)->data)
        BSTDelete(&(*t)->rchild, key);
    else{
        if((*t)->lchild==NULL){
            BiTNode *p = *t;
            *t = (*t)->rchild;
            free(p);
        }
        else if((*t)->rchild==NULL){
            BiTNode *p = *t;
            *t = (*t)->lchild;
            free(p);
        }
        else
        {
            BiTNode *p, *q;
            p = *t;
            q = (*t)->lchild;
            while (q->rchild!=NULL)
            {
                p = q;
                q = q->rchild;
            }
            (*t)->data = q->data;

            if(p==*t)
                p->lchild = q->lchild;
            else
                p->rchild = q->lchild;
            free(q);
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

int main(){
    BiTree t = NULL;
    int list[] = {2, 5, 4, 6, 3, 7, 1};
    create(&t, list, 7);
    BSTInsert(&t, 10);

    InOrder(t);
    BSTDelete(&t, 10);
    

    printf("\n");
    InOrder(t);
    printf("\n");
    BiTNode *p = BSTSearch(t, 10);
    if(p==NULL)
        printf("not found");
    else
        printf("%d", p->data);

    return 0;
}