#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode
{
    int key;
    int count;
    struct BTNode *lchild, *rchild;
}BTNode;

void insertNode(BTNode **t,int k){
    if (*t == NULL)
    {
        *t = (BTNode *)malloc(sizeof(BTNode));
        (*t)->key = k;
        (*t)->count = 1;
        (*t)->lchild = (*t)->rchild = NULL;
    }
    else{
        if ((*t)->key == k)
            (*t)->count++;
        else if ((*t)->key > k)
            insertNode(&(*t)->lchild, k);
        else
            insertNode(&(*t)->rchild, k);
    }
}

void InOrder(BTNode *t){
    if(t!=NULL){
        InOrder(t->lchild);
        printf("%d,%d ", t->key, t->count);
        InOrder(t->rchild);
    }
}

int main(){
    BTNode *t = NULL;
    insertNode(&t, 5);
    insertNode(&t, 4);
    insertNode(&t, 2);
    insertNode(&t, 1);
    insertNode(&t, 1);
    insertNode(&t, 1);
    insertNode(&t, 1);
    insertNode(&t, 1);
    insertNode(&t, 1);
    insertNode(&t, 6);

    InOrder(t);
    return 0;
}