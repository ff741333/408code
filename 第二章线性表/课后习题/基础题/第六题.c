//有一个递增非空单链表，设计一个算法删除值域重复的结点
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{  //单向链表结构体
    int data;
    struct LNode* next;
}LNode,* LinkList;

void InitList(LinkList *list){  //指针传递
    *list=(LNode*)malloc(sizeof(LNode));
    if(*list==NULL) return;
    (*list)->next=NULL;  //括号！！
}
void DeleteSame(LinkList *list){
    LNode *p=(*list)->next;
    while (p->next!=NULL)
    {
        while (p->data==p->next->data)
        {
            p->next = p->next->next;
        }
        p = p->next;
    }  
}

int getLen(LinkList list){
    LNode* p = list->next;
    int i=0;
    while(p!=NULL){
        p=p->next;
        i++;
    }
    return i;
}
/*按次序查找*/
LNode* getItem(LinkList list, int i){ 
    if(i<0) return NULL;
    LNode* p;
    p=list;
    int j=0;
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
/*按位插入*/
int InsertList(LinkList *list,int e,int i){ 
    if(i<1) return 0;
    /*LNode* p = *list;
    int j=0;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }*/
    LNode* p = getItem(*list,i-1);
    if(p==NULL) return 0;
    LNode* r = (LNode*)malloc(sizeof(LNode));
    r->data=e;
    r->next=p->next;
    p->next=r;
    return 1;
}

void show(LinkList list){
    LNode* p = list->next;
    printf("单链表为:");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n长度:%d\n",getLen(list));
}

int main(){
    LinkList list;
    InitList(&list);
    InsertList(&list, 9, 1);
    InsertList(&list, 8, 1);
    InsertList(&list, 8, 1);
    InsertList(&list, 8, 1);
    InsertList(&list, 7, 1);
    InsertList(&list, 7, 1);
    InsertList(&list, 7, 1);
    InsertList(&list, 7, 1);
    InsertList(&list, 6, 1);
    InsertList(&list, 6, 1);
    InsertList(&list, 6, 1);
    show(list);
    DeleteSame(&list);
    show(list);
    return 0;
}