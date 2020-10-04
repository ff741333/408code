#include<stdio.h>
#define MAX 2147483647

/*直接插入排序*/
void insertSort(int arr[],int n){
    if(n<=1)
        return;
    int temp,i,j;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }  
}

/*选择插入排序*/
void selectSort(int arr[],int n){
    if(n<=1)
        return;
    int min, temp, i, j;
    for (i = 0; i < n; i++){
        min = i;        
        for (j = i+1; j < n; j++)
            if(arr[j]<arr[min])
                min = j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    } 
}

/*冒泡排序*/
void bubleSort(int arr[],int n){
    int i, j, flag;
    int temp;

    for (i = 0; i < n-1; i++)
    {
        flag = 0;
        for (j = 0; j < n-1; j++)
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        if(flag==0)
            break;
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
    //insertSort(arr, 10);
    //selectSort(arr, 10);
    bubleSort(arr, 10);
    show(arr, 10);
    return 0;
}