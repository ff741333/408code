//汉诺塔递归 时间复杂度o（2的n次方）
#include<stdio.h>

void hanoi(int n, char a, char b, char c)
{
    if(n==1)
        printf("%c-%c ", a, c);
    else {
        hanoi(n - 1, a, c, b);
        printf("%c-%c ", a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main(){
    hanoi(3, 'a', 'b', 'c');
    return 0;
}