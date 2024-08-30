#include <stdio.h>
#include <stdlib.h>

int min = 100;

void func(int n, int cnt){
    if(n == 1){
        if(cnt <= min){
            min = cnt;
            return;
        }
    }
    else{
        if(n % 3 == 0){
            func(n / 3, cnt + 1);
        }
        if(n % 2 == 0){
            func(n / 2, cnt + 1);
        }
        func(n - 1, cnt + 1);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    func(n, 0);
    printf("%d", min);
}