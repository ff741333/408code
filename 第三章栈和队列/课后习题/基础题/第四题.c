#include<stdio.h>

int legal(char ch[]){
    int i = 1;
    int count = 0;
    while (ch[i]!='\0')
    {
        if(count<0)
            return 0;
        if(ch[i]=='I')
            count++;
        else if (ch[i]=='O')
            count--;
        i++;
    }
    if(count==0)
        return 1;
    else
        return 0;
}
int main(){
    char ch[]={'I','O','I','O','\0'};
    printf("%d\n", legal(ch));
    printf("%c", ch[4]);
    return 0;
}