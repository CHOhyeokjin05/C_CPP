#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[6];
    char e_l[6];
}meb;


int compare(const void* a, const void* b){
    meb A = *(meb*)a;
    meb B = *(meb*)b;

    if(strcmp(A.name, B.name) > 0){
        return -1;
    }
    else{
        return 1;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    meb* member;
    member = (meb*)malloc(sizeof(meb) * n);

    for(int i=0; i<n; i++){
        scanf("%s %s", member[i].name, member[i].e_l);
    }
    qsort(member, n, sizeof(meb), compare);

    for(int i=0; i<n; i++){
        if(strcmp(member[i].name, member[i+1].name) == 0){
            i++;
        }
        else{
            printf("%s\n", member[i].name);
        }
    }
}