#include "stdio.h"
#include "math.h"
int min(int one,int two){
    if (two>one){
        return one;
    }else{
        return two;
    }
}
int jumpSearch(int arr[], int x, int n){
    int step = sqrt(n);
    int half = step/2;
    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n){
            return -1;
        }
    }
    if (arr[prev + half]==x){
        return prev + half;
    }else if(arr[prev + half]<x){
        for(int i = prev+half;i<step+1;i++){
            if(arr[i]==x){
                return i;
            }
        }
    }else{
        for(int j = prev;j < prev+half+1;j++){
            if(arr[j]==x){
                return j;
            }
        }


    }
    return -1;

}
int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 8, 13, 21,
                 34, 55, 89, 144, 233, 377, 610};
    int x =2;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);
    printf("%d\n",index);

    if (index!=-1){
        printf("%d is at index %d",x,index);
    } else{
        printf("No data found.\n");
    }
    return 0;
}