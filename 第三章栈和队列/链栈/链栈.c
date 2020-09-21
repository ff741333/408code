#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode{ //链栈结构体定义
    int data;
    struct LinkNde* next;
}*LiStack;

void InitLiStack(LiStack* stack){
    *stack=NULL;
}

int Push(LiStack* stack,int e){
    LiStack p = (LiStack)malloc(sizeof(struct LinkNode));
    if(p==NULL) return 0;
    p->data=e;
    p->next=*stack;
    *stack=p;
    return 1;
}

int Pop(LiStack* stack,int* e){
    if(*stack==NULL) return 0;
    LiStack p = *stack;
    *e=p->data;
    *stack=(*stack)->next;
    free(p);
    return 1;
}

int main(){
    LiStack stack;
    int e;
    InitLiStack(&stack);
    Push(&stack,1);
    Push(&stack,2);
    Push(&stack,3);
    Push(&stack,4);
    printf("%d",stack->data);
    Pop(&stack,&e);
    printf(" %d ",e);
    printf("%d",stack->data);
    return 0;
}
