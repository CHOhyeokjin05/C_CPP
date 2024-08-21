#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node* next;
}node;

node* Head;
node* Tail;

void insert(int n){
    for(int i=0; i<n; i++){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->num = i + 1;
        if(Head == NULL){
            Head = newNode;
            Tail = newNode;
        }
        else{
            Tail->next = newNode;
            Tail = newNode;
        }
        Tail->next = NULL;
    }
}

void last(){
    Tail->next = Head;
    Tail = Head;
    Head = Head->next;
    Tail->next = NULL;
}

int main(){
    int n;
    scanf("%d", &n);

    insert(n);

    // n == 1 일 때, accessnullpointer 에러 발생!
    while(1){
        if(n==1){
            printf("%d", Head->num);    // Head = Head->next 가능!
            break;
        }
        else{
            Head = Head->next;
            if(Head->next != NULL){
                last();
            }
            else{
                printf("%d", Head->num);
                break;
            }
        }

    }
}