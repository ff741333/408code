#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255

typedef struct {  //顺序表储存串
    char ch[MAXLEN];
    int length;
}SString;

int SubString(SString *Sub,SString string,int pos,int len){  //求子串,用Sub返回串S的pos个字符起长度为len的子串
    if(pos+len-1>string.length) return 0;
    for (int i = pos; i < pos + len;i++)
    {
        Sub->ch[i - pos + 1] = string.ch[i];
    }
    Sub->length = len;
    return 1;
}

int StrCompare(SString s,SString t){  //求字符串的大小 如果s大于y 返回>0, s小于t 返回<0，s等于t 返回=0
    for (int i = 1; i < s.length+1 && i < t.length+1; i++)
    {
        if(s.ch[i]!=t.ch[i])
            return s.ch[i] - t.ch[i];
    }
    return s.length-t.length;
}
/*
int Index(SString s,SString t){ 
    int i = 1, n = s.length, m = t.length;
    SString Sub;
    while(i<n-m){
        SubString(&Sub, s, i, m);
        if(StrCompare(Sub,t)==0)
            return i;
        else ++i;
    }
    return 0;
}
*/

int Index(SString s,SString t){ //改进的朴素模式匹配算法
    int k = 1;
    int i = k, j = 1;
    while (i<=s.length && j<=t.length)
    {
        if(s.ch[i]==t.ch[j]){
            ++i;
            ++j;
        }
        else {
            k++;
            i = k;
            j = 1;
        }
    }
    if(j>t.length) return k;
    else return 0;
}

void Get_Next(SString t,int *next){ //求KMP算法的next数组
    int i = 1, j = 0;
    next[1] = 0;
    while(i<t.length){
        if(j==0 || t.ch[i]==t.ch[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
    //数组优化 将指向元素的值设为相同
    for (int k = 2; k <= t.length;k++){
        if(t.ch[next[k]]==t.ch[j])
            next[j] = next[next[k]];
    }
}
int Index_KMP(SString s,SString t){ //KMP算法
    int i = 1, j = 1;
    int next[t.length + 1];
    Get_Next(t,next);
    while(i<=s.length&&j<=t.length){
        if(j==0||s.ch[i]==t.ch[j]){
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if(j>t.length)
        return i - t.length;
    else
        return 0;
}
void show(SString string){
    for (int i = 1; i < string.length+1; i++)
    {
        printf("%c ", string.ch[i]);
    }       
}

int main(){
    SString string;
    SString s;
    /*for (int i = 65; i < 85;i++)
    {
        string.ch[i - 64] = i;
    }
    string.length = 20;
    for (int i = 65; i < 85;i++)
    {
        s.ch[i - 64] = i;
    }
    s.length = 20;
    SubString(&s, string, 4, 5);
   // printf("%d\n", StrCompare(s, string));
*/
    s.ch[1] = 'a';
    s.ch[2] = 'b';
    s.ch[3] = 'a';
    s.ch[4] = 'b';
    s.length = 4;
    string.ch[1] = 'c';
    string.ch[2] = 'b';
    string.ch[3] = 'c';
    string.ch[4] = 'b';
    string.ch[5] = 'a';
    string.ch[6] = 'b';
    string.length = 6;

    
    printf("%d,%d\n", Index(string, s), Index_KMP(string, s));
    show(string);
    printf("\n");
    show(s);
    return 0;
}


/*
typedef struct {  //堆分配储存串
    char *ch;
    int length;
}HString;
    HString string;
    string.ch = (char *)malloc(sizeof(char)); //用完记得free！

typedef struct StringNode{  //链表存储串
    char ch[10];
    struct StringNode *next;
} StringNode, *Sting;
*/