#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int age;
    char name[101];
}mem;
mem sorted[100001];
void merge(mem member[], int start, int middle, int end){
    int left = start;
    int right = middle + 1;
    int k = start;
    while(left <= middle && right <= end){
        if(member[left].age <= member[right].age){
            sorted[k] = member[left];
            left++;
        }
        else{
            sorted[k] = member[right];
            right++;
        }
        k++;
    }
    while(left<=middle){
        sorted[k] = member[left];
        left++;
        k++;
    }
    while(right<=end){
        sorted[k] = member[right];
        right++;
        k++;
    }
    for(int i=start; i<=end; i++){
        member[i] = sorted[i];
    }
}
void mergesort(mem member[], int start, int end){
    if(start == end){
        return;
    }
    else{
        int middle = (start + end) / 2;
        mergesort(member, start, middle);
        mergesort(member, middle + 1, end);
        merge(member, start, middle, end);
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    mem* member = (mem*)malloc(sizeof(mem) * n);

    for(int i=0; i<n; i++){
        scanf("%d %s", &member[i].age, member[i].name);
    }
    mergesort(member, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d %s\n", member[i].age, member[i].name);
    }
}