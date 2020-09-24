//设计一个算法，将一个头节点为A的单链表（其数据域为整数）分解成两个单链表A和B，使得A链表只含有原来链表中data域中为奇数的结点，而B链表只含有原链表中data域中为偶数的结点，且保持原来相对的顺序
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

LinkList Depart(LinkList list){
    LinkList B;
    InitList(&B);
    LNode *p = list, *q=B;
    while (p->next!=NULL)
    {
        if(p->next->data%2==0){
            q->next = p->next;
            p->next = p->next->next;
            q = q->next;
        }
        else
            p = p->next;
    }
    return B;
}
int main(){
    LinkList list;
    LinkList B;
    InitList(&list);
    for (int i = 20; i > 10;i--)
        InsertNextList(list, i);
    show(list);
    B=Depart(list);
    show(B);
    show(list);
    return 0;
}