#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{  //双向链表结构体
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

int InitList(DLinkList* list){
    *list=(DNode* )malloc(sizeof(DNode));
    if(*list==NULL) return 0;
    (*list)->next=NULL;
    (*list)->prior=NULL;
    return 1;
}

int InsertNextList(DNode* p,DNode* s){
    if(p==NULL || s==NULL) return 0;
    s->next=p->next;
    if(p->next!=NULL){
        p->next->prior=s;
    }
    s->prior=p;
    p->next=s;
    return 1;
}

void show(DLinkList list){
    if(list==NULL) {
        printf("链表错误!");
        return;
    }
    printf("双向链表为:");
    DNode* p = list;
    while(p->next!=NULL){
        p=p->next;
        printf("%d ",p->data);
    }
    printf("\n倒序为:");
    while(p->prior!=NULL){
        printf("%d ",p->data);
        p=p->prior;
    }
    printf("\n");

}

int DeleteList(DNode* list){ //删除后继结点
    if(list==NULL) return 0;
    DNode *p = list->next;
    if(p==NULL) return 0;
    list->next=p->next;
    if(p->next!=NULL){
        p->next->prior=list;
    }
    free(p);
    return 1;
}

void DestoryList(DLinkList *list){
    while((*list)->next!=NULL){
        DeleteList(*list);
    }
    free(*list);
    *list=NULL;
}
int main(){
    DLinkList list;
    InitList(&list);
    DNode* p = (DNode* )malloc(sizeof(DNode));
    p->data=1;
    InsertNextList(list,p);
    p = (DNode* )malloc(sizeof(DNode));
    p->data=2;
    InsertNextList(list,p);
    show(list);
    DestoryList(&list);
    show(list);
    return 0;
}
