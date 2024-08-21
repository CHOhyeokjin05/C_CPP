#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int lower_bound(int* arr, int target, int start, int end){
    int middle = (start + end) / 2;
    while(start < end){
        middle = (start + end) / 2;
        if(target > arr[middle]){
            start = middle + 1;
        }
        else{
            end = middle;
        }
    }
    return end;
}

int upper_bound(int* arr, int target, int start, int end){
    int middle = (start + end) / 2;
    while(start < end){
        middle = (start + end) / 2;
        if(target >= arr[middle]){
            start = middle + 1;
        }
        else{
            end = middle;
        }
    }
    if(target == arr[end]){
        end++;
    }
    return end;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(sizeof(int) * n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    int m;
    scanf("%d", &m);

    int lower;
    int upper;
    int target;

    for(int i=0; i<m; i++){
        scanf("%d", &target);
        lower = lower_bound(arr, target, 0, n-1);
        upper = upper_bound(arr, target, 0, n-1);
        printf("%d ", upper - lower);
    }
}