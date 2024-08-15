#include <stdio.h>
#include <string.h>
int main(){
    char ch[60];
    int n;
    int r = 31;
    long long M = 1234567891;
    scanf("%d %s", &n, ch);
    long long sum = 0, hash = 1;
    for(int i=0; i<n; i++){
        sum += (ch[i] - 'a' + 1) * (hash % M) % M;
        hash *= r; hash %= M;
    }

    printf("%lld", sum % M);
}