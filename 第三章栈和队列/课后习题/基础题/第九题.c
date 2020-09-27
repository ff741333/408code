//编写一个算法，将一个非负的十进制数N转换为一个二进制数
#include<stdio.h>
#define MAXSIZE 10

int change(int e){
    int stack[MAXSIZE];
    int top = -1;
    while(e!=0){
        ++top;
        stack[top] = e % 2;
        e = e / 2;
    }
    while (top>-1)
    {
        e = e * 10 + stack[top];
        --top;
    }
    return e;
}

int main(){
    printf("%d", change(255));
    return 0;
}
