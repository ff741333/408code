#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct{  //共享栈结构体定义
    int data[MAXSIZE];
    int top0;
    int top1;
}ShStack;

//初始化栈
void InitStack(ShStack* stack){
    stack->top0=-1;
    stack->top1=MAXSIZE;
}

int IsFull(ShStack stack){  //判断栈是否满
    if(stack.top0==stack.top1-1) return 1;
    else return 0;
}
