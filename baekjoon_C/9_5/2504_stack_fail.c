#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char ch;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

Stack* stack;

char pop(){
    char popdata;
    Node* temp = stack->top;
    stack->top = temp->next;
    popdata = temp->ch;
    free(temp);
    return popdata;
}

void insert(char ch){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->next = stack->top;
    stack->top = newNode;
}


int main(){
    char ch[100];
    scanf("%s", ch);

    stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;

    int tmp = 1, sum = 0;
    int sw = 1;
    for(int i=0; i<strlen(ch); i++){
        if(ch[i] == '(' || ch[i] == '['){
            insert(ch[i]);
            if(ch[i] == '('){
                tmp *= 2;
                sw = 1;
            }
            else{
                tmp *= 3;
                sw = 1;
            }
        }
        else{
            if(stack->top != NULL){
                if(stack->top->ch == '(' && ch[i] == ')' && sw){
                    sum += tmp;
                    sw = 0;
                    tmp /= 2;
                    pop();
                }
                else if(stack->top->ch == '[' && ch[i] == ']' && sw){
                    sum += tmp;
                    sw = 0;
                    tmp /= 3;
                    pop();
                }
                else{
                    if(stack->top->ch == '(' && ch[i] == ')'){
                        tmp /= 2;
                        pop();
                    }
                    else if(stack->top->ch == '[' && ch[i] == ']'){
                        tmp /= 3;
                        pop();
                    }
                    else{
                        printf("0");
                        return 0;
                    }
                }
            }
            else{
                printf("0");
                return 0;
            }
        }
    }
    if(stack->top == NULL)
        printf("%d", sum);
    else
        printf("0");
}