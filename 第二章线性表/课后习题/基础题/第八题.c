//设计一个算法将带头节点的单链表L逆置
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{  //单向链表结构体
    int data;
    struct LNode* next;
}LNode,* LinkList;

/*初始化*/
void InitList(LinkList* list){  //指针传递
    *list=(LNode*)malloc(sizeof(LNode));
    if(*list==NULL) return;
    (*list)->next=NULL;  //括号！！
}

/*得到链表长度*/
int getLen(LinkList list){
    LNode* p = list->next;
    int i=0;
    while(p!=NULL){
        p=p->next;
        i++;
    }
    return i;
}

/*后插*/
int InsertNextList(LNode* list,int e){  //后插
    if(list==NULL) return 0;
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if(p==NULL) return 0;
    p->data=e;
    p->next=list->next;
    list->next=p;
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

void InvertList(LinkList list){
    LNode *p, *q = list->next;
    list->next = NULL;
    while (q!=NULL)
    {
        p = q->next;
        q->next = list->next;
        list->next = q;
        q = p;
    }  
}

int main(){
    LinkList list;
    InitList(&list);
    for (int i = 0; i < 10;i++)
        InsertNextList(list, i);
    show(list);
    InvertList(list);
    show(list);
    return 0;
}
