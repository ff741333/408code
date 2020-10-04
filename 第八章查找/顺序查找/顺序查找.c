#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{  //单向链表结构体
    int data;
    struct LNode* next;
}LNode,* LinkList;

int SearchList(int arr[],int n,int key){
    for (int i = 0; i < n; i++)
        if(arr[i]==key)
            return i;
    return -1;
}

LNode *SearchLinkList(LinkList list,int key){
    LNode *p = list->next;
    while (p!=NULL)
    {
        if(p->data==key)
            return p;
        p = p->next;
    }
    return NULL;
}