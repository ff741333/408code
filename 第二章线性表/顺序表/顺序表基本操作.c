#include<stdio.h>
#define MaxSize 10
typedef struct{
    int data[MaxSize];  //��̬����������
    int length;  //���嵱ǰ˳�����
}SqList;
/*
��ʼ��
*/
void InitList(SqList &L){
    for(int i=0;i<MaxSize;i++){
        //L.data[i]=0;
        L.length=0;
    }
}
/*��׳�Բ������*/
bool ListInsert(SqList &L,int i,int e){
    if(i<1||i>L.length)
        return false;  //�����λ����Ч
    if(L.length>MaxSize)
        return false;  //˳�������
    for(int j=L.length;j>=i;j--){  //����i��Ԫ�ؼ�֮���Ԫ�غ��ƣ���Ϊi����λ��length�����ȣ��������Ǵ�0��ʼ��
        L.data[j]=L.data[j-1];  //���統ǰ����Ϊ5������j=5����ָ�����j[5]��������Ԫ�أ���j[5]=j[4]���Դ����ƣ���j=2��ʱ�����ѭ������ʱ��ֹ��j[3]=j[2]
    }
    L.data[i-1]=e;  //��λ��i����e
    L.length++;  //���鳤�ȼ�1
    return true;
}
/*��׳��ɾ������*/
bool ListDelete(SqList &L,int i,int &e){
    if(i<1||i>L.length)
        return false;  //ɾ����λ����Ч
    e=L.data[i-1];  //��ɾ����Ԫ�ظ���e��ע��eһ��Ҫ���������ͣ���Ȼ�޷�����������
    for(int j=i;j<L.length;j++){  //����i��λ�ú��Ԫ��ǰ��
        L.data[j-1]=L.data[j];
    }
    L.length--;  //���ȼ�һ
    return true;
}
/*��λ���Ҳ���*/
int GetInt(SqList L,int i){
    return L.data[i-1];
}
/*��ֵ����  ������λ��*/
int LocateInt(SqList L,int e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e)
            return i+1;
    }
    return 0;  //�˳�ѭ��˵������ʧ��
}
int main(){
    SqList L;
    InitList(L);
    for(int i=0;i<5;i++){
        L.data[i]=i+1;
        L.length++;
    }
    ListInsert(L,3,6);
    printf("\n��ǰ˳�����Ϊ%d\n",L.length);
    for(int j=0;j<L.length;j++){
        printf("%d\n",L.data[j]);
    }
    printf("ֵΪ3�����ݵ�λ����%d\n",LocateInt(L,3));
    return 0;
}
