#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char ch[501];
}list;

int compare(const void* a, const void*b){
    list A = *(list*)a;
    list B = *(list*)b;
    if(strcmp(A.ch, B.ch) > 0){
        return 1;
    }
    else{
        return -1;
    }
}

int binary_search(list arr[], char target[], int start, int end){
    int middle = (start + end) / 2;

    if(start > end){
        return 0;
    }
    else{
        if(strcmp(arr[middle].ch, target) < 0){
            binary_search(arr, target, middle + 1, end);
        }
        else if(strcmp(arr[middle].ch, target) == 0){
            return 1;
        }
        else{
            binary_search(arr,target, start, middle-1);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    list* arr = (list*)malloc(sizeof(list) * n);
    for(int i=0; i<n; i++){
        scanf("%s", arr[i].ch);
    }
    qsort(arr, n, sizeof(list), compare);

    char target[501];
    int tmp, count = 0;

    for(int i=0; i<m; i++){
        scanf("%s", target);
        tmp = binary_search(arr, target, 0, n-1);
        count += tmp;
    }
    printf("%d", count);
}