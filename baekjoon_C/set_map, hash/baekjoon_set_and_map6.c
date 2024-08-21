#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
    char name[21];
}list;

int compare(const void* a, const void* b){
    list A = *(list*)a;
    list B = *(list*)b;

    if(strcmp(A.name, B.name) > 0){
        return 1;
    }
    else{
        return -1;
    }
}

int binary_search(list* arr, char target[], int start, int end){
    int middle = (start + end) / 2;
    if(start > end){
        return 0;
    }
    else{
        if(strcmp(arr[middle].name, target) > 0){
            binary_search(arr, target, start, middle - 1);
        }
        else if(strcmp(arr[middle].name, target) == 0){
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

    list* arr = (list*)malloc(sizeof(list) * n);
    for(int i=0; i<n; i++){
        scanf("%s", arr[i].name);
    }

    qsort(arr, n, sizeof(list), compare);

    list* brr = (list*)malloc(sizeof(list) * m);
    for(int i=0; i<m; i++){
        scanf("%s", brr[i].name);
    }

    qsort(brr, m, sizeof(list), compare);

    list tmp[500000];
    int cnt = 0;

    if(n >= m){
        for(int i=0 ; i<n; i++){
            if(binary_search(brr, arr[i].name, 0, m-1)){
                cnt++;
                strcpy(tmp[cnt-1].name, arr[i].name);
            }
        }
    }
    else{
        for(int i=0; i<m; i++){
            if(binary_search(arr, brr[i].name, 0, n-1)){
                cnt++;
                strcpy(tmp[cnt-1].name, brr[i].name);
            }
        }
    }
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++){
        printf("%s\n", tmp[i].name);
    }

}