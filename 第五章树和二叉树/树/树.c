#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct Branch
{
    int cIdx;
    struct Branch *next;
}Branch;

typedef struct 
{
    int data;
    struct Branch *first;
}TNode;

/*土办法构造一个树*/
void create(TNode tree[]){
    for (int i = 0; i < 6; i++)
    {
        tree[i].data = i;
        tree[i].first = NULL;
    }
    Branch *p = (Branch *)malloc(sizeof(Branch));
    p->cIdx = 1;
    p->next = NULL;
    tree[0].first = p;

    Branch *r = (Branch *)malloc(sizeof(Branch));
    r->cIdx = 2;
    r->next = NULL;
    p->next = r;
    p = p->next;

    r = (Branch *)malloc(sizeof(Branch));
    r->cIdx = 3;
    r->next = NULL;
    p->next = r;

    p = (Branch *)malloc(sizeof(Branch));
    p->cIdx = 4;
    p->next = NULL;
    tree[1].first = p;

    r = (Branch *)malloc(sizeof(Branch));
    r->cIdx = 5;
    r->next = NULL;
    p->next = r;
}

void visit(TNode *node){
    printf("%d", node->data);
}

/*树的先根遍历*/
void preOrder(TNode *p,TNode tree[]){
    if(p!=NULL){
        visit(p);
        Branch *q;
        q = p->first;
        while (q!=NULL)
        {
            preOrder(&tree[q->cIdx], tree);
            q = q->next;
        }       
    }
}

/*树的后根遍历*/
void postOrder(TNode *p,TNode tree[]){
    if(p!=NULL){
        Branch *q;
        q = p->first;
        while (q!=NULL)
        {
            postOrder(&tree[q->cIdx], tree);
            q = q->next;
        }
        visit(p);       
    }
}

/*树的层次遍历*/
void level(TNode *tn,TNode tree[]){
    TNode *queue[MAXSIZE];
    int front, rear;
    front = rear = 0;
    TNode *p;
    Branch *q;
    if (tn!=NULL)
    {
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = tn;
        while(rear != front){
            front = (front + 1) % MAXSIZE;
            p = queue[front];
            visit(p);
            q = p->first;
            while(q != NULL){
                rear = (rear + 1) % MAXSIZE;
                queue[rear] = &tree[q->cIdx];
                q = q->next;
            }
        }
    }
    
}


int main(){
    TNode tree[6];
    create(tree);
    preOrder(tree,tree);
    printf("\n");
    postOrder(tree, tree);
    printf("\n");
    level(tree, tree);
    return 0;
}

