#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{  //单向链表结构体
    int data;
    struct LNode* next;
}LNode,* LinkList;

void InitList(LinkList* list){  //指针传递
    *list=(LNode*)malloc(sizeof(LNode));
    if(*list==NULL) return;
    (*list)->next=NULL;  //括号！！
}

LNode* getItem(LinkList list, int i){ //按次序查找
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

LNode* selectItem(LinkList list,int e){ //按值查找
    LNode* p;
    p=list->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
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

int InsertList(LinkList *list,int e,int i){ //按位插入
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
int InsertNextList(LNode* list,int e){  //后插
    if(list==NULL) return 0;
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if(p==NULL) return 0;
    p->data=e;
    p->next=list->next;
    list->next=p;
    return 1;
}

int InsertPriorList(LNode* list,int e){ //前插
    if(list==NULL) return 0;
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if(p==NULL) return 0;
    p->data=list->data;
    p->next=list->next;
    list->next=p;
    list->data=e;
    return 1;
}

int DeleteList(LinkList* list,int i,int *e){ // 根据次序删除
    if(i<1) return 0;
   /* LNode* p=*list;
    int j=0;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }*/
    LNode* p = getItem(*list,i-1);
    if(p==NULL) return 0;
    LNode* q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
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

void TailInsertList(LinkList* list){
/*    *list=(LNode*)malloc(sizeof(LNode));
    if(*list==NULL) return;
    (*list)->next=NULL;*/
    InitList(list);
    int e;
    LNode *p,*q;
    q=*list;

    while(scanf("%d",&e)!=EOF){
        p = (LNode*)malloc(sizeof(LNode));
        p->data=e;
        q->next=p;
        q=p;
    }
    q->next=NULL;
}
void HeadInsertList(LinkList* list){
    /*    *list=(LNode*)malloc(sizeof(LNode));
    if(*list==NULL) return;
    (*list)->next=NULL;*/
    InitList(list);
    int e;
    LNode* p;
    while(scanf("%d",&e)!=EOF){
        InsertList(list,e,1);
        /*p=(LNode*)malloc(sizeof(LNode));
        p->data=e;
        p->next=(*list)->next;
        (*list)->next=p;*/
    }
}

void InvertList(LinkList list){
    LNode* p = list->next;
    list->next = NULL;
    LNode* q;
    while(p!=NULL){
        q=p->next;
        p->next=list->next;
        list->next=p;
        p=q;
    }
}
int main(){
    LinkList list;
    InitList(&list);

    /*HeadInsertList(&list);
    show(list);*/
    InsertList(&list,1,1);
    InsertList(&list,2,1);
    InsertList(&list,5,1);
    InsertList(&list,6,2);
    InsertPriorList(list->next,10);
    show(list);
    InvertList(list);
    show(list);
    int e;
    DeleteList(&list,1,&e);
    show(list);
    LNode* p = selectItem(list,11);
    if(p!=NULL)printf("\n%d",p->data);
    else printf("\nerror");
 //   printf("\n%d",selectItem(list,1));
    return 0;
}
