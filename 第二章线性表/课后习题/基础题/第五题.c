//将顺序表L中所有小于表头元素的整数放在前边部分，大于表头元素的整数放在后半部分
#include<stdio.h>
#define MaxSize 30
typedef struct{
    int data[MaxSize];  //静态数组存放数据
    int length;  //定义当前顺序表长度
}SqList;

void move(SqList *list){
    int temp;
    int i = 0, j = list->length - 1;

    temp = list->data[i];
    while (i<j)
    {
        while (i<j&&list->data[j]>temp)
            --j;
        if(i<j){
            list->data[i] = list->data[j];
            ++i;
        }

        while (i<j&&list->data[i]<temp)
            ++i;
        if(i<j){
            list->data[j] = list->data[i];
            --j;
        }
    }
    list->data[i] = temp;
}

void show(SqList list){
    for(int i=0;i<list.length;i++){
        printf("%d ",list.data[i]);
    }
    printf("\n");
}
int main(){
    SqList a ;
    a.length = 0;
    /*for(int i=0;i<11;i++){
        //scanf("%d", &a.data[i]);
        a.data[i]=i;
        //if(a.data[i]==0)
        //    break;
        a.length++;
    }*/
    a.data[0] = 4;
    a.data[1] = 6;
    a.data[2] = 4;
    a.data[3] = 5;
    a.data[4] = 2;
    a.data[5] = 7;
    a.length = 6;

    show(a);
    move(&a);
    show(a);
    return 0;
}