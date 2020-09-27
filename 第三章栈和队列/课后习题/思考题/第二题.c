//设计一个递归算法，求n个不同字符的所有全排序列
#include<stdio.h>
#define N 4
void show(char ch[],int k){
    int i, j;
    char temp;
    if(k==0){
        for (j = 0; j < N; ++j)
            printf("%c", ch[j]);
        printf("\n");
    }
    else{
        for (i = 0; i <= k; ++i){
            temp = ch[k];
            ch[k] = ch[i];
            ch[i] = temp;
            show(ch, k - 1);
            temp = ch[i];
            ch[i] = ch[k];
            ch[k] = temp;
        }
    }
}
int main(){
    char a[] = {'a', 'b', 'c', 'd'};
    show(a,3);
    return 0;
}