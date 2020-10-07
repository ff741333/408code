#include<stdio.h>

typedef struct BTNode
{
    int data;
    struct BTNode *lchild, *rchild;
    int lsize;
}BTNode;

BTNode *search_small(BTNode *t,int k){
    if(t==NULL||k<1)
        return NULL;
    else {
        if (t->lsize == k)
            return t;
        else if (t->lsize > k)
            return search_small(t->lchild, k);
        else
            return search_small(t->rchild, k - t->lsize);
    }
}
