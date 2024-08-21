#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b){
    return *(long long*)a - *(long long*)b;
}
int binary_search(long long* arr, long long target, int start, int end){
    if(start > end){
        return 0;
    }
    else{
        int middle = (start + end) / 2;
        if(target < arr[middle]){
            binary_search(arr, target, start, middle - 1);
        }
        else if(target == arr[middle]){
            return 1;
        }
        else{
            binary_search(arr, target, middle + 1, end);
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);

    long long* arr = (long long*)malloc(sizeof(long long) * n);
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }

    qsort(arr, n, sizeof(long long), compare);

    int m;
    scanf("%d", &m);

    long long* brr = (long long*)malloc(sizeof(long long) * m);
    for(int i=0; i<m; i++){
        scanf("%lld", &brr[i]);
        printf("%d\n", binary_search(arr, brr[i], 0, n-1));
    }

}