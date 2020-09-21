#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define INITSIZE 5

typedef struct{  //顺序表结构体
    int maxsize; //最大长度
    int length;  //长度
    int *data;
}List;

void InitList(List *list){
    list->data= (int *)malloc(sizeof(int)*INITSIZE);
    list->length = 0;
    list->maxsize = INITSIZE;
}

void IncreaseSize(List *list,int len){
    int *p=list->data;
    list->data = (int *) malloc((list->maxsize+len)*sizeof(int));
    for(int i=0;i<list->length;i++){
        list->data[i]=p[i];
    }
    list->maxsize+=len;
    free(p);
}

int InsertList(List *list, int e,int i){ //按位插入
    if(i<1 || i>list->length+1)
        return 0;
    if(list->length>=list->maxsize)
        return 0;
    for(int j=list->length;j>=i;j--) {
        list->data[j]=list->data[j-1];
    }
    list->data[i-1]=e;
    list->length++;
    return 1;
}

int DeleteList(List* list,int i,int *e){ //按位删除
    if(i<1 || i>list->length)
        return 0;
    *e = list->data[i-1];
    for(int j=i-1;j<list->length;j++){
        list->data[j]=list->data[j+1];
    }
    list->length--;
    return 1;
}

void show(List *list){
    for(int i=0;i<list->length;i++){
        printf("%d\n",list->data[i]);
    }
}

int getItem(List* list,int i) { //按位查找
    return list->data[i-1];
}
int selectItem(List* list,int e){ //按值查找
    int i =-1;
    for(int j=0 ; j<list->length ;j++){
        if(list->data[j]==e) i=j+1;
    }
    return i;
}
int main(){
    List a ;
    InitList(&a);

    printf("\n!!%d\n",a.maxsize);
    for(int i=0;i<a.maxsize;i++){
        a.data[i]=i;
        a.length++;
    }

    show(&a);
    IncreaseSize(&a,2);
    int e=-1;
    printf("%d??\n",selectItem(&a,2));
    //printf("%d\n",e);

    show(&a);
    printf("\n!!%d",a.length);
    return 0;
}
