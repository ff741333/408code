#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{ //循环单链表
    int data;
    struct LNode* next;
}LNode,*LinkList;

int InitList(LinkList* list){
    *list = (LNode* )malloc(sizeof(LNode));
    if(*list==NULL) return 0;
    (*list)->next=list;
    return 1;
}

int IsEmpty(LinkList list){
    if(list->next==list) return 1;
    else return 0;
}

int IsTail(LinkList list,LNode* p){
    if(p->next==list) return 1;
    else return 0;
}
//**********************************************************//
typedef struct DNode{ //循环双向链表
    int data;
    struct DNode* next;
}DNode,*DLinkList;

int InitDList(DLinkList* list){
    *list = (LNode* )malloc(sizeof(LNode));
    if(*list==NULL) return 0;
    (*list)->next=list;
    (*list)->prior=list;
    return 1;
}

//判断为空，判断是否为尾节点等同循环单链表


int InsertNextDList(DNode* p,DNode* s){
    s->next=p->next;
    s->prior=p;
    p->next->prior=s;
    p->next=s;
}

int DeleteDList(DNode* p){
    DNode* q = p->next;
    q->next->prior=p;
    p->next=q->next;
    free(q);
}

