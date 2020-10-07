#include<stdio.h>

void changePost(int pre[],int post[],int low1,int high1,int low2,int high2){
    if (low1 <= high1){
        post[high2] = pre[low1];
        changePost(pre, post, low1 + 1, (low1 + 1 + high1) / 2, low2, (low2 + high2 - 1) / 2);
        changePost(pre, post, (low1 + 1 + high1) / 2 + 1, high1, (low2 + high2 - 1) / 2 + 1, high2 - 1);
    }
}

int main(){
    int b[7] = {1, 2, 4, 5, 3, 6, 7};
    int post[7];
    changePost(b, post, 0, 6, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", post[i]);
    }
    
}