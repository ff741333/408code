#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{ //ѭ��������
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
typedef struct DNode{ //ѭ��˫������
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

//�ж�Ϊ�գ��ж��Ƿ�Ϊβ�ڵ��ͬѭ��������


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

