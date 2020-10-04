#include<stdio.h>
#define MAX 2147483647

void shellSort(int arr[],int n){
    int temp;
    int gap, i, j;
    for (gap = n/2; gap>0; gap/=2)
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }    
}

void show(int arr[],int n){
    printf("数列为:");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {2, 1, 5, 4, 9, 8, 6, 4, 7, 4};
    show(arr, 10);
    shellSort(arr, 10);
    show(arr, 10);
    return 0;
}