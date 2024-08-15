#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    int x = *(int*)a;
    int y = *(int*)b;

    if(x>y){
        return 1;
    }
    else if(x==y){
        return 0;
    }
    else{
        return -1;
    }
}

int b_search(int arr[], int target, int start, int end){
    if(start > end){
        return 0;
    }
    else{
        int middle = (start + end) / 2;
        if(arr[middle] == target){
            return 1;
        }
        else if(arr[middle] < target){
            b_search(arr, target, middle + 1, end);
        }
        else{
            b_search(arr, target, start, middle - 1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1000000];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    int brr[1000000];
    int k;
    scanf("%d", &k);

    for(int i=0; i<k; i++){
        scanf("%d", &brr[i]);
        printf("%d ", b_search(arr, brr[i], 0, n-1));
    }
    return 0;
}