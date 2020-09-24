//从一给定的顺序表L中删除下标i-j(i<=j,包括i、j)的所有元素，假定i、j都是合法的
#include<stdio.h>
#define MaxSize 30
typedef struct{
    int data[MaxSize];  //静态数组存放数据
    int length;  //定义当前顺序表长度
}SqList;

/*删除i-j的元素*/
void DeleteIJ(SqList *list,int i,int j){
    ++j;
    for (; j < list->length; i++, j++){
        list->data[i] = list->data[j];
    }
    list->length = i;
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
    for(int i=0;i<11;i++){
        a.data[i]=i;
        a.length++;
    }
    show(a);
    DeleteIJ(&a,4,9);
    show(a);
    return 0;
}