#include <stdio.h>

int arr0[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

int arrsum(int k, int n){
    int sum = 0;
    if(k == 0){
        return arr0[n-1];
    }
    else{
        for(int i=1; i<=n; i++){
            sum += arrsum(k-1, i);
        }
        return sum;
    }
}

int main(){
    int m;
    scanf("%d", &m);

    int k, n;
    for(int i=0; i<m; i++){
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n", arrsum(k, n));
    }
}