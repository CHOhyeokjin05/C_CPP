#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int binary_search(int arr[], int target, int start, int end){
    if(start > end){
        return -1;
    }
    else{
        int middle = (start + end) / 2;
        if(target < arr[middle]){
            binary_search(arr, target, start, middle - 1);
        }
        else if(target == arr[middle]){
            return middle;
        }
        else{
            binary_search(arr, target, middle + 1, end);
        }
    }
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

    int target;
    int index, tmp;
    int cnt;
    for(int i=0; i<m; i++){
        scanf("%d", &target);
        int cnt = 1;
        index = binary_search(arr, target, 0, n-1);
        if(index == -1){
            printf("0 ");
        }
        else{
            tmp = index;
            while(arr[index] == arr[index + 1]){
                cnt++;
                index++;
            }
            index = tmp;
            while(arr[index] == arr[index - 1]){
                cnt++;
                index--;
            }
            printf("%d ", cnt);
        }
    }
}