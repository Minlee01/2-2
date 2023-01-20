/*
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

#define MAX_VERTICES 100
#define NUM 10
typedef struct element {
	int data;
}element;

typedef struct HeapType {
	element heap[MAX_VERTICES];
	int heap_size;
}HeapType;

void set_init(HeapType* minheap) {
	minheap->heap_size = 0;
}

//decrease the element i¡¯s value to ¡®key¡¯
void Decrease_key_min_heap(element A[], int i, int key)
{
	int temp;
	if (key >= A[i].data) {
		printf("error: new key is not smaller than current key");
		return;
	}
	//Implement your code below.
	A[i].data = key;
	while ((i > 1) && (A[i / 2].data > A[i].data)) {
		temp = A[i / 2].data;
		A[i / 2].data = A[i].data;
		A[i].data = temp;
		i /= 2;
	}
}
int compare(int x, int y, element A[]) {
	if (A[x].data > A[y].data)
		return y;
	else
		return x;
}

//Increase the element i¡¯s value to ¡®key¡¯
void Increase_key_min_heap(element A[], int i, int key)
{
	int temp;
	if (key <= A[i].data) {
		printf("error: new key is not larger than current key");
		return;
	}
	A[i].data = key;
	//Implement your code below.
	int smaller = compare(2 * i, (2 * i) + 1, A);
	while ((i > 1) && (A[smaller].data) && (smaller <= NUM)) {
		temp = A[i].data;
		A[i].data = A[smaller].data;
		A[smaller].data = temp;
		i = smaller;
		smaller = compare(2 * i, (2 * i) + 1, A);
	}
}


int main() {
	int keys[] = { 1, 4, 2, 7, 5, 3, 3, 7, 8, 9 };

	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	set_init(h);

	for (int i = 0; i < NUM; i++) {
		h->heap[i + 1].data = keys[i];
	}
	h->heap_size = NUM + 1;
	Decrease_key_min_heap(h->heap, 4, 3);
	for (int i = 1; i < NUM + 1; i++) {
		printf("%d ", h->heap[i].data);
	}
	printf("\n");

	Increase_key_min_heap(h->heap, 3, 10);
	for (int i = 1; i < NUM + 1; i++) {
		printf("%d ", h->heap[i].data);
	}
	return 0;
}
*/