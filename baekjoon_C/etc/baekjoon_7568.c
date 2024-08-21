#include <stdio.h>
#include <stdlib.h>

typedef struct man{
    int weight;
    int height;
    int grade;
}man;


int main(){
    int n;
    scanf("%d", &n);

    man* arr = (man*)malloc(sizeof(man) * n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &arr[i].weight, &arr[i].height);
        arr[i].grade = 1;
    }

    int weight, height;
    for(int i=0; i<n; i++){
        weight = arr[i].weight;
        height = arr[i].height;
        for(int j=0; j<n; j++){
            if(weight < arr[j].weight && height < arr[j].height){
                arr[i].grade++;
            }
            else{
                continue;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i].grade);
    }

}