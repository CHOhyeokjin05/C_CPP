#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *a, const void *b);
int dup_check(char* s);
int main(void) {
	int cnt = 0;
	char s[1001];

	scanf("%s", s);
	cnt += dup_check(s);

	printf("%d", cnt);
	
	return 0;
}
int compare(const void* a, const void* b) {
	return strcmp(*(const char **)a, *(const char **)b);
}
int dup_check(char* s) {
	char* dup[1001];

	int count = 0;
	int len = strlen(s);

	for (int i = 0; i < len; i++) {
		dup[i] = &s[i];
	}

	qsort(dup, len, sizeof(char*), compare);

	for (int i = 0; i < len - 1; i++) {
		int k = 0;
		while (dup[i][k] == dup[i + 1][k]) {
			k++;
		} 
		count += strlen(dup[i]) - k;
	}

	count += strlen(dup[len - 1]);

	return count;
}
