#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch1[10], ch2[10], ch3[10];
    int target;

    scanf("%s", ch1);
    scanf("%s", ch2);
    scanf("%s", ch3);

    if(atoi(ch1) > 0){
        target = atoi(ch1) + 3;
    }
    else if(atoi(ch2) > 0){
        target = atoi(ch2) + 2;
    }
    else{
        target = atoi(ch3) + 1;
    }

    if(target % 3 == 0 && target % 5 == 0){
        printf("FizzBuzz");
    }
    else if(target % 3 == 0){
        printf("Fizz");
    }
    else if(target % 5 == 0){
        printf("Buzz");
    }
    else{
        printf("%d", target);
    }
}