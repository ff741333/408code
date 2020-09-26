//有N个个位正整数存放在int型数组A[0,...,N-1]中,N为已定义的常量且N<=9，数组A[]的长度为N，另给一个int型变量i，要求只用上述变量（A[0]-A[N-1]与i，这个N+1个整型变量）写一个算法，找出这N个整数中的最小者，并且要求不能破坏数组A[]中的数据
#include<stdio.h>
#define N 8

int FinMin(int A[]){
    int i;
    for ( i = 9; i < N*10; i+=10)
    {
        if(A[i/10]<i%10) 
            i = i - i % 10 + A[i/10];
    }
    return i % 10;
}
int main(){
    int A[N]={4,5,3,8,9,7,6,2};
    printf("%d", FinMin(A));
    return 0;
}