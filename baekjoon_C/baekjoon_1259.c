#include <stdio.h>
#include <string.h>
int main()
{
    char ch[50];
    scanf("%s", ch);
    while(ch[0] != '0'){
        int sw = 1;
        for(int i=0; i<strlen(ch); i++){
            if(ch[i] != ch[strlen(ch)-i-1]){
                sw = 0;
                break;
            }
        }
        if(sw)
            printf("yes\n");
        else
            printf("no\n");
        scanf("%s", ch);
    }
}