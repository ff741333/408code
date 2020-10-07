#include<stdio.h>

void countSort(int A[],int B[],int n){
    int i, j, count;
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
            if(A[i]>A[j])
                count++;
        B[count] = A[i];
    }
}

void show(int arr[],int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int A[6] = {2, 3, 5, 1, 4, 6};
    int B[6];
    show(A, 6);
    countSort(A, B, 6);
    show(B, 6);

    return 0;
}