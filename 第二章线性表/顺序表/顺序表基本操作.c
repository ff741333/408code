#include<stdio.h>
#define MaxSize 10
typedef struct{
    int data[MaxSize];  //静态数组存放数据
    int length;  //定义当前顺序表长度
}SqList;
/*
初始化
*/
void InitList(SqList &L){
    for(int i=0;i<MaxSize;i++){
        //L.data[i]=0;
        L.length=0;
    }
}
/*健壮性插入操作*/
bool ListInsert(SqList &L,int i,int e){
    if(i<1||i>L.length)
        return false;  //插入的位序无效
    if(L.length>MaxSize)
        return false;  //顺序表满了
    for(int j=L.length;j>=i;j--){  //将第i个元素及之后的元素后移，因为i代表位序，length代表长度，而数组是从0开始的
        L.data[j]=L.data[j-1];  //比如当前长度为5，先令j=5，则指向的是j[5]，第六个元素，令j[5]=j[4]，以此类推，当j=2的时候结束循环，此时截止到j[3]=j[2]
    }
    L.data[i-1]=e;  //在位置i安放e
    L.length++;  //数组长度加1
    return true;
}
/*健壮性删除操作*/
bool ListDelete(SqList &L,int i,int &e){
    if(i<1||i>L.length)
        return false;  //删除的位序无效
    e=L.data[i-1];  //被删除的元素赋给e，注意e一定要是引用类型，不然无法传回主函数
    for(int j=i;j<L.length;j++){  //将第i个位置后的元素前移
        L.data[j-1]=L.data[j];
    }
    L.length--;  //长度减一
    return true;
}
/*按位查找操作*/
int GetInt(SqList L,int i){
    return L.data[i-1];
}
/*按值查找  返回其位序*/
int LocateInt(SqList L,int e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e)
            return i+1;
    }
    return 0;  //退出循环说明查找失败
}
int main(){
    SqList L;
    InitList(L);
    for(int i=0;i<5;i++){
        L.data[i]=i+1;
        L.length++;
    }
    ListInsert(L,3,6);
    printf("\n当前顺序表长度为%d\n",L.length);
    for(int j=0;j<L.length;j++){
        printf("%d\n",L.data[j]);
    }
    printf("值为3的数据的位次是%d\n",LocateInt(L,3));
    return 0;
}
