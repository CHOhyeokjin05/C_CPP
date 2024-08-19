#include<stdio.h>
#include<stdlib.h>

int SIZE = 100;
struct bucket* hashTable = NULL;

struct node {
	int key;
	char* value;
	struct node* next;
	struct node* previous;
};

struct bucket {
	int count;
	struct node* head;
};

struct node* createNode(int key, char* value) {
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key = key;
	newNode->value = value;    // strdup를 통해 메모리 공간 할당해 주어야 함, 중복 포인터 지정 위험 존재
	newNode->next = NULL;
	newNode->previous = NULL;
	return newNode;
}


int makeKey(char* key) {
	int hash = 143;
	for (; *key; key++) {
		hash = hash * 3 + *key;
	}
	return hash % 2000000000;
}

int hashFunction(int key) {
	return key % SIZE;
}

void insert(char* value) {
	int key = makeKey(value);
	int hashIndex = hashFunction(key);
	struct node* newNode = createNode(key, value);
	if (hashTable[hashIndex].count == 0) {
		hashTable[hashIndex].count = 1;
		hashTable[hashIndex].head = newNode;
	}
	else {
		hashTable[hashIndex].count++;
		hashTable[hashIndex].head->previous = newNode;
		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
	}
	return;
}

int search(char* value) {
	int key = makeKey(value);
	int hashIndex = hashFunction(key);
	struct node* node = hashTable[hashIndex].head;
	int flag = 0;
	while (node != NULL) {
		if (node->key == key) {
			flag = 1;
			break;
		}
		node = node->next;
	}
	return flag;
}

int main() {
	int n, m;
	char str[501];
	int ans = 0;
	hashTable = (struct bucket*)malloc(sizeof(struct bucket) * SIZE);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < SIZE; i++) {
		hashTable[i].count = 0;
		hashTable[i].head = NULL;
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		insert(str);
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", str);
		ans += search(str);
	}
	printf("%d", ans);
	free(hashTable);
	return 0;
}