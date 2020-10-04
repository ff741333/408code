#include<stdio.h>

void merge(int arr[], int low, int mid, int high){
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int l1[n1], l2[n2];

    for (i = 0; i < n1; i++)
        l1[i] = arr[low + i];
    for (i = 0; i < n2; i++)
        l2[i] = arr[mid + 1 + i];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if(l1[i]<l2[j])
            arr[k++] = l1[i++];
        else
            arr[k++] = l2[j++];
    }

    while (i<n1)
        arr[k++] = l1[i++];
    while (j<n2)
        arr[k++] = l2[j++];
}

void mergeSort(int arr[],int low,int high){
    if (low < high){
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void show(int arr[], int n){
    printf("数列为:");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {2, 1, 5, 4, 9, 8, 6, 4, 7, 4};
    show(arr, 10);

    mergeSort(arr, 0, 9);

    show(arr, 10);
    return 0;
}