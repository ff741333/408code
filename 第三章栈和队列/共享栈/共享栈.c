#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct{  //����ջ�ṹ�嶨��
    int data[MAXSIZE];
    int top0;
    int top1;
}ShStack;

//��ʼ��ջ
void InitStack(ShStack* stack){
    stack->top0=-1;
    stack->top1=MAXSIZE;
}

int IsFull(ShStack stack){  //�ж�ջ�Ƿ���
    if(stack.top0==stack.top1-1) return 1;
    else return 0;
}
