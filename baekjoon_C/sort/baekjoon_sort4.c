#include <stdio.h>
int sorted[10000];
void mergesort(int arr[], int start, int end);
void merge(int arr[], int start, int middle, int end);

void mergesort(int arr[], int start, int end){
    int middle;
    if(start == end){
        return;
    }
    else{
        middle = (start + end) / 2;
        mergesort(arr, start, middle);
        mergesort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}
void merge(int arr[], int start, int middle, int end){
    int left = start;
    int right = middle + 1;
    while(left <= middle && right <= end){
        if(arr[left] <= arr[right]){
            sorted[left] = arr[left];
            left++;
        }
        else{
            sorted[right] = arr[right];
            right++;
        }
    }
    while(left <= middle){
        sorted[left] = arr[left];
        left++;
    }
    while(right <= end){
        sorted[right] = arr[right];
        right++;
    }
    for(int i=start; i<end; i++){
        arr[i] = sorted[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }

}