#include <stdio.h>
#include <stdlib.h>
int binary_search(int brr[], int target, int start, int end){
    if(start > end){
        return 0;
    }
    else{
        int middle = (start + end) / 2;
        if(brr[middle] < target){
            binary_search(brr, target, middle + 1, end);
        }
        else if(brr[middle] == target){
            return middle;
        }
        else{
            binary_search(brr, target, start, middle-1);
        }
    }
}

int compare(const void* a, const void* b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(A > B){
        return 1;
    }
    else{
        return -1;
    }
}
int del(int brr[], int n){
    int tmp[10000];
    int cnt = 0;
    tmp[cnt] = brr[0];
    cnt++;
    for(int i=1; i<n; i++){
        if(brr[i] == brr[i-1]){
            continue;
        }
        else{
            tmp[cnt] = brr[i];
            cnt++;
        }
    }
    for(int i=0; i<n; i++){
        brr[i] = tmp[i];
    }
    return cnt;
}


int main()
{
    int n;
    scanf("%d", &n);

    int arr[10001], brr[10001];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        brr[i] = arr[i];
    }
    qsort(brr, n, sizeof(int), compare);
    int cnt = del(brr,n);
    for(int i=0; i<n; i++){
        printf("%d ", binary_search(brr, arr[i], 0, cnt - 1));
    }
    
}