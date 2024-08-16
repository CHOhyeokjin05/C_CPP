#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int compare(const void* a, const void* b) {
    Point A = *(Point*)a;
    Point B = *(Point*)b;
    if (A.x > B.x) {
        return 1;
    }
    else if (A.x == B.x) {
        if (A.y > B.y) {
            return 1;
        }
        else {
            return -1;
        }
    }
    return -1;
}

int main() {
    int test;
    scanf("%d", &test);
    Point* arr;    // 구조체 포인터
    arr = (Point*)malloc(sizeof(Point) * test);    // 구조체 동적할당
    for (int i = 0; i < test; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, test, sizeof(Point), compare);    // qsort (quick sort) c 내장함수
                                                 // void qsort (void *base, size_t nel, size_t width, int (*compare)(const void *, const void *);
                                                 // int (*compare)은 함수 포인터
    for (int i = 0; i < test; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
    free(arr);

    return 0;
}
    // compare 추가
    // a < b일 때는 -1을 반환
    // a > b일 때는 1을 반환
    // a == b일 때는 0을 반환