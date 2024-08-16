#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int len;
    char ch[100];
}Voc;

int compare(const void* a, const void* b){
    Voc A = *(Voc*)a;
    Voc B = *(Voc*)b;
    if(A.len > B.len){
        return 1;
    }
    else if(A.len == B.len){
        if(strcmp(A.ch, B.ch) > 0){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }

}

int main()
{
    int n;
    scanf("%d", &n);

    Voc* set = (Voc*)malloc(sizeof(Voc) * n);
    char tmp[100];
    for(int i=0; i<n; i++){
        scanf("%s", set[i].ch);
        set[i].len = strlen(set[i].ch);
    }
    qsort(set, n, sizeof(Voc), compare);

    printf("%s\n", set[0].ch);
    for(int i=1; i<n; i++){
        if(strcmp(set[i].ch, set[i-1].ch))
            printf("%s\n", set[i].ch);
        else
            continue;
    }
}