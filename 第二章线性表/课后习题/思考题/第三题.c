//试编写一个函数，以不多于3n/2的平均比较次数，在一个有n个整数的顺序表A中找出最大值和最小值
#include<stdio.h>
#define MaxSize 30
typedef struct{
    int data[MaxSize];  //静态数组存放数据
    int length;  //定义当前顺序表长度
}SqList;

//最坏情况：表中从大到小非递增排序，数据比较次数为2（n-1）
//最好情况，表中从小到大递增排序，数据比较次数为n-1
//A中数据有效性是等可能的，因此最好和最坏的概率是等可能的，都是1/2
//综上所述，数据的平均比较次数为3n/2
void Find(SqList list,int *max,int *min){
    if(list.length==0)
        return ;
    *max = list.data[0];
    *min = list.data[0];

    for (int i = 1; i < list.length;i++){
        if(list.data[i]>*max){
            *max = list.data[i];
        }
        else if(list.data[i]<*min){
            *min = list.data[i];
        }
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
    int max, min;
    Find(a, &max, &min);
    printf("最大值：%d,最小值：%d", max, min);
    return 0;
}
