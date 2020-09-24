//请设计一个算法，将顺序表中的所有元素逆置
#include<stdio.h>
#define MaxSize 30
typedef struct{
    int data[MaxSize];  //静态数组存放数据
    int length;  //定义当前顺序表长度
}SqList;
/*倒置算法*/
void Inverse(SqList *list){
    int temp;
    for (int i = 0, j = list->length - 1; i < j; i++, j--){
        temp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = temp;
    }
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
    Inverse(&a);
    show(a);
    return 0;
}
