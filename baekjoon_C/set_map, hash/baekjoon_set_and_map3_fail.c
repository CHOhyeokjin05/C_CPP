#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

struct node{
    int key;
    char* name;
    int el;
    struct node* next;
};
struct bucket{
    int count;
    struct node* head;
};

struct bucket* hashtable = NULL;


struct node* createNode(int key, char* name, int el){
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->name = (char*)malloc(strlen(name) + 1);
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->el = 1;
    newNode->next = NULL;
    return newNode;
}
int makekey(char* name){
    int rate = 1, hash = 0;
    for(int i=0; i<5; i++){
        rate *= 17;
    }
    for(;*name;name++){
        hash += rate * (*name - 'A');
        rate /= 17;
    }
    return hash % 200000000;
}
int hashfunction(int key){
    return key % SIZE;
}

void insert(char* name){
    int key = makekey(name);
    int hashIndex = hashfunction(key);
    struct node* newNode = createNode(key, name, 1);
    if(hashtable[hashIndex].count == 0){
        hashtable[hashIndex].count = 1;
        hashtable[hashIndex].head = newNode;
    }
    else{
        hashtable[hashIndex].count++;
        newNode->next = hashtable[hashIndex].head;
        hashtable[hashIndex].head = newNode;
    }
}

void erase(char* name){
    int key = makekey(name);
    int hashIndex = hashfunction(key);
    struct node* node = hashtable[hashIndex].head;
    while(node != NULL){
        if(node->key == key && node->el == 1){
            node->el = 0;
            break;
        }
        node = node->next;
    }
}


int main(){

    hashtable = (struct bucket*)malloc(sizeof(struct bucket) * SIZE);
    for(int i=0; i<SIZE; i++){
        hashtable[i].head = NULL;
        hashtable[i].count = 0;
    }

    int n;
    scanf("%d", &n);


    char name[6], el[6];

    for(int i=0; i<n; i++){
        scanf("%s %s", name, el);
        if(strcmp(el, "enter") == 0){
            insert(name);
        }
        else{
            erase(name);
        }
    }

    for(int i=SIZE - 1; i>=0; i--){
        struct node* node = hashtable[i].head;
        while(node != NULL){
            if(node->el == 1){
                printf("%s\n", node->name);    
            }
            node = node->next;
        }
    }

    // 할당된 메모리 해제 (선택적이지만 권장됨)
    for (int i = 0; i < SIZE; i++) {
        struct node* node = hashtable[i].head;
        while (node != NULL) {
            struct node* temp = node;
            node = node->next;
            free(temp->name);
            free(temp);
        }
    }
    free(hashtable);
    return 0;
}