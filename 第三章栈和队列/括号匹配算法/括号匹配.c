#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
//顺序栈实现括号匹配算法
typedef struct{
    char data[MAXSIZE];
    int top;
}SqStack;


void InitStack(SqStack* stack){
    stack->top=-1;
}

int IsEmpty(SqStack stack){
    if(stack.top==-1) return 1;
    else return 0;
}

int Push(SqStack* stack,char e){
    if(stack->top==MAXSIZE-1) return 0;
    stack->top++;
    stack->data[stack->top]=e;
    return 1;
}

int Pop(SqStack* stack,char* e){
    if(IsEmpty(*stack)) return 0;
    *e=stack->data[stack->top];
    stack->top--;
    return 1;
}

int BracketCheck(char* str,int len){
    SqStack stack;
    InitStack(&stack);
    for(int i=0;i<len;i++){
        if(str[i]=='{'||str[i]=='['||str[i]=='('){
            Push(&stack,str[i]);
           }
        else if(str[i]=='}'||str[i]==']'||str[i]==')'){//放过字符串中所有不是括号的字符
            if(IsEmpty(stack)) return 0;
            char popelement;
            Pop(&stack,&popelement);
            if(str[i]=='}' && popelement!='{') return 0;
            else if(str[i]==']' && popelement!='[') return 0;
            else if(str[i]==')' && popelement!='(') return 0;
        }
    }
    return IsEmpty(stack);
}

int main(){
    SqStack stack;
    char a[10]={'{','{','{','1','[',']',')','}','}','}'};
    //char a[4]={'(','[',']',')'};
    printf("%d",BracketCheck(a,10));
    //printf("%d",GetLength(a));
    return 0;
}
