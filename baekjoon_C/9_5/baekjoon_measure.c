#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int x, y, div, total;

    for(int i=0; i<n; i++){
        div = 2;
        total = 1;
        scanf("%d %d", &x, &y);
        while(x >= div && y >= div){
            if(x % div == 0 && y % div == 0){
                x /= div;
                y /= div;
                total *= div;
            }
            else{
                div++;
            }

        }
        printf("%d\n", total * x * y);
    }
}