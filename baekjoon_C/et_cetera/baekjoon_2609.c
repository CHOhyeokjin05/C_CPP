#include <stdio.h>
int max(int a, int b){
    int n = 2;
    int total = 1;
    while(a >= n && b >= n){
        while(a%n == 0 && b%n == 0){
            a /= n; b /= n;
            total *= n;
        }
        n += 1;
    }
    return total;
}
int min(int a, int b){
    int n = 2;
    int total = 1;
    while(a >= n && b >= n){
        while(a%n == 0 && b%n == 0){
            a /= n; b /= n;
            total *= n;
        }
        n += 1;
    }
    return total * a * b;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", max(a,b));
    printf("\n%d", min(a,b));
}