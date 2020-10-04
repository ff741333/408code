#include<stdio.h>

void sift(int arr[],int low,int high){
    int i = low, j = 2 * i + 1;
    int temp = arr[i];
    while (j <= high)
    {
        if (j < high && arr[j] < arr[j + 1])
            ++j;
        if (temp < arr[j]){
            arr[i] = arr[j];
            i = j;
            j = i * 2 + 1;
        }
        else
            break;
    }
    arr[i] = temp;
}

void headSort(int arr[],int n){
    int i;
    int temp;
    for (i = n / 2 - 1; i >= 0; i--)
        sift(arr, i, n - 1);
    for (i = n - 1; i > 0; i--)
    {
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        sift(arr, 0, i - 1);
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
    headSort(arr, 10);
    show(arr, 10);

    return 0;
}