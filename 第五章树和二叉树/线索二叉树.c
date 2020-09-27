#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
    int ltag, rtag;
} BiTNode, *BiTree;

