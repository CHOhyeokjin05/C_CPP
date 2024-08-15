#include <stdio.h>
#include <string.h>
int hash(char ch[], int n){
    int arr[100];
    int r = 31;
    long long M = 1234567891;
    for(int i=0; i<n; i++){
        arr[i] = ch[i] - 'a' + 1;
    }
    long long sum = 0, hash = 1;
    for(int i=0; i<n; i++){
        sum += (long long)arr[i] * hash;
        hash *= r;
    }
    return (long)sum % M;
}
int main(){
    char ch[60];
    int n;
    scanf("%d %s", &n, ch);
    printf("%d", hash(ch, n));
}
// 또는 나머지의 성질을 이용해서 sum을 할 때 (arr[i] % M) * (hash % M)