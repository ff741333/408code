//设计一个算法删除单链表L（有头节点）中的一个最小值结点
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

/*后插*/
int InsertNextList(LNode* list,int e){  
    if(list==NULL) return 0;
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if(p==NULL) return 0;
    p->data=e;
    p->next=list->next;
    list->next=p;
    return 1;
}

void DeleteMin(LinkList list){
    LNode *pre = list, *p = list->next, *minNode = p, *minPriorNode = pre;
    while (p!=NULL)
    {
        if(p->data<minNode->data){
            minNode = p;
            minPriorNode = pre;
        }
        p = p->next;
        pre = pre->next;
    }
    minPriorNode->next = minNode->next;
    free(minNode);
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
    InsertNextList(list,1);
    InsertNextList(list,2);
    InsertNextList(list,-5);
    InsertNextList(list,-1);
    InsertNextList(list,5);
    show(list);
    DeleteMin(list);
    show(list);
    DeleteMin(list);
    show(list);
    return 0;
}