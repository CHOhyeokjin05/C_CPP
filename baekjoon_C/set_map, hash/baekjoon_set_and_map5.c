#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[200000001] = {0,};
    
    int key = 100000000, index;
    for(int i=0; i<n; i++){
        scanf("%d", &index);
        arr[key + index]++;
    }
    
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", index);
        printf("%d ", arr[key + index]);
    }
}