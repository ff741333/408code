#include<stdio.h>
#define MAX 2147483647

void quickSort(int arr[],int low,int high){
    int temp;
    int i = low, j = high;
    if(low<high){
        temp = arr[i];
        while (i<j)
        {
            while (i < j && temp < arr[j])
                j--;
            if(i<j){
                arr[i] = arr[j];
                i++;
            }
            while (i < j && temp > arr[i])
                i++;
            if(i<j){
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = temp;
        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
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
    quickSort(arr, 0, 9);
    show(arr, 10);
    return 0;
}