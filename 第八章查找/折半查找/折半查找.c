#include<stdio.h>

int BSearch(int arr[],int low,int high,int key){
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid-1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a = BSearch(arr, 3, 5, 7);
    printf("%d", a);
    return 0;
}