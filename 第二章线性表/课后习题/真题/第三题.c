#include<stdio.h>
#define N 9

void show(int A[]){
    printf("数组为:");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int FindMain(int A[]){
    int c = A[0];
    int count = 1;
    for (int i = 1; i < N; i++)
    {
        if(A[i]==c)
            count++;
        else {
            if (count>0)
                count--;
            else
                c = A[i];
        }
    }
    count = 0;
    for (int i = 0; i < N; i++)
    {
        if(A[i]==c)
            count++;
    }
    if(count>N/2)
        return c;
    else
        return -1;
}

int FindMain2(int A[]){
    int count;
    for (int i = 0; i < (N+1)/2; i++)
    {
        count = 0;
        for (int j = 0; j < N; j++)
        {
            if(A[i]==A[j])
                count++;
        }
        if(count>N/2)
            return A[i];
    }
    return -1;
}
int main(){
    int A[N]={3,3,3,3,4,4,4,4,4};
    printf("%d,%d", FindMain(A), FindMain2(A));
    return 0;
}