#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    char ch[100];
    int cnt = 0, tf = 1;
    for(int i=0; i<n; i++){
        scanf("%s", ch);
        for(int j=0; j<strlen(ch); j++){
            if(ch[j] == '('){
                cnt += 1;
            }
            else if(ch[j] == ')' && cnt > 0){
                cnt -= 1;
            }
            else{
                tf = 0;
                break;
            }
        }
        if(cnt != 0){
            tf = 0;
        }
        if(tf == 1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        cnt = 0;
        tf = 1;
    }
}