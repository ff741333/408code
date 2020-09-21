#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct{ //顺序栈结构体定义
    int data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack* stack){
    stack->top=-1;
}

int Push(SqStack* stack,int e){
    if(stack->top==MAXSIZE-1) return 0;
    stack->top++;
    stack->data[stack->top]=e;
    return 1;
}

int Pop(SqStack* stack,int* e){
    if(stack->top==-1) return 0;
    *e=stack->data[stack->top];
    stack->top--;
    return 1;
}

int GetTop(SqStack stack,int* e){
    if(stack.top==-1) return 0;
    *e=stack.data[stack.top];
    return 1;
}

int main(){
    SqStack stack;
    int e;
    InitStack(&stack);
    Push(&stack,1);
    Push(&stack,2);
    Push(&stack,3);
    Push(&stack,4);
    GetTop(stack,&e);
    printf("%d",e);
    Pop(&stack,&e);
    printf("%d",e);
    GetTop(stack,&e);
    printf("%d",e);
    return 0;
}
