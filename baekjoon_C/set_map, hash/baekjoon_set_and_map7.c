#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int binary_search(int* arr, int target, int start, int end){
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
    int n, m;
    scanf("%d %d", &n, &m);

    int* aset = (int*)malloc(sizeof(int) * n);
    int* bset = (int*)malloc(sizeof(int) * m);

    for(int i=0; i<n; i++){
        scanf("%d", &aset[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%d", &bset[i]);
    }
    qsort(aset, n, sizeof(int), compare);
    qsort(bset, m, sizeof(int), compare);

    int acnt = n;
    int bcnt = m;

    for(int i=0; i<n; i++){
        bcnt -= binary_search(bset, aset[i], 0, m-1);
    }
    for(int i=0; i<m; i++){
        acnt -= binary_search(aset, bset[i], 0, n-1);
    }
    printf("%d", acnt + bcnt);

}