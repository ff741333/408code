//见第三章课后题思考题第四题
#include<stdio.h>
#define MaxSize 30
typedef struct{
    int data[MaxSize];  //静态数组存放数据
    int length;  //定义当前顺序表长度
}SqList;

/*比较顺序表A，B的大小，A>B返回1，A=B返回0，否则返回-1*/
int CompareList(SqList A,SqList B){
    int i = 0;
    while(i<A.length&&i<B.length){
        if(A.data[i]!=B.data[i]){
            if(A.data[i]>B.data[i])
                return 1;
            else
                return -1;
        }
        ++i;
    }
    if(i==A.length&&i==B.length)
        return 0;
    else if(i==A.length)
        return -1;
    else if(i==B.length)
        return 1;
}
void show(SqList list){
    for(int i=0;i<list.length;i++){
        printf("%d ",list.data[i]);
    }
    printf("\n");
}

int main(){
    SqList a, b;
    a.length = 0;
    for(int i=0;i<9;i++){
        a.data[i]=i;
        a.length++;
    }
    b.length = 0;
    for(int i=0;i<10;i++){
        b.data[i]=i;
        b.length++;
    }
    b.data[2] = -1;
    show(a);
    show(b);
    printf("%d", CompareList(a, b));
    return 0;
}
