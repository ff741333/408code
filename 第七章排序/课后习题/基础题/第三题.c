#include<stdio.h>

void doublepuple(int arr[],int n){
    int flag = 1, temp;
    int left = 0, right = n - 1;
    while (flag==1)
    {
        flag = 0;
        for (int i = left; i < right; i++)
            if(arr[i]>arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
            }
        right--;
        for (int i = right; i > left; i--)
            if (arr[i] < arr[i - 1])
            {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                flag = 1;
            }
        left++;
    }  
}

void show(int arr[],int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int A[6] = {2, 3, 5, 1, 4, 6};
    show(A, 6);
    doublepuple(A, 6);
    show(A, 6);

    return 0;
}