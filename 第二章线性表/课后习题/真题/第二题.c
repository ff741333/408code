#include<stdio.h>
#define N 20


//空间复杂度O（1），时间复杂度O（n）
void clf(int *R,int p){
    int i, j, temp;
    for (i = 0, j = p; i < j;i++,j--){
        temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }
    for (i = p+1, j = N-1; i < j;i++,j--){
        temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }
    for (i = 0, j = N-1; i < j;i++,j--){
        temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }
}

void show(int R[]){
    for (int i = 0; i < N; i++)
    {
        printf("%d ", R[i]);
    }
    printf("\n");
}

int main(){
    int R[N];
    for (int i = 0; i < N; i++)
        R[i] = i;
    show(R);
    clf(R, 2);
    show(R);
    return 0;
}