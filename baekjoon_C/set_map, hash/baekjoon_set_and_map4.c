#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int n;
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

int binary_search(list dic[], char name[], int start, int end){
    int middle = (start + end) / 2;
    if(start > end){
        return 0;
    }
    else{
        if(strcmp(dic[middle].name, name) > 0){
            binary_search(dic, name, start, middle - 1);
        }
        else if(strcmp(dic[middle].name, name) == 0){
            return dic[middle].n;
        }
        else{
            binary_search(dic, name, middle + 1, end);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    list* dic = (list*)malloc(sizeof(list) * n);

    for(int i=0; i<n; i++){
        scanf("%s", dic[i].name);
        dic[i].n = i + 1;
    }

    list* dic_i = (list*)malloc(sizeof(list) * n);
    for(int i=0; i<n; i++){
        dic_i[i] = dic[i];
    }

    qsort(dic, n, sizeof(list), compare);

    char cmd[21];
    for(int i=0; i<m; i++){
        scanf("%s", cmd);
        if(atoi(cmd) <= n && atoi(cmd) > 0){
            printf("%s\n", dic_i[atoi(cmd) - 1].name);
        }
        else{
            printf("%d\n", binary_search(dic, cmd, 0, n-1));
        }
    }
}