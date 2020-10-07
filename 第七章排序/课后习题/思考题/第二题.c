#include<stdio.h>

int checkTOrder(int arr[],int n){
    for (int i = 0; i < n; i++)
        for (int j = i+2; j < n; j++)
            if ((arr[i] > arr[i + 1] && arr[i] < arr[j]) || (arr[i] < arr[i + 1] && arr[i] > arr[j]))
                return 0;
    return 1;
}

int main(){
    int arr[8] = {20, 30, 90, 80, 40, 50, 70, 60};
    printf("%d", checkTOrder(arr, 8));

    return 0;
}