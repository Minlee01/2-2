#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 8
#define INF 1000L
#define TRUE 1
#define FALSE 0

typedef struct element {
	int edge;
	int vertex;
} element;

typedef struct {
	element* heap;
	int heap_size;
} HeapType;

int weight[MAX_VERTICES][MAX_VERTICES] =
{ { 0,3,INF,INF,INF,INF,INF,14 },
{ 3,0,8,INF,INF,INF,INF,10 },
{ INF,8,0,15,2,INF,INF,INF },
{ INF,INF,15,0,INF,INF,INF,INF },
{ INF,INF,2,INF,0,9,4,5 },
{ INF,INF,INF,INF,9,0,INF,INF },
{ INF,INF,INF,INF,4,INF,0,6 },
{ 14,10,INF,INF,5,INF,6,0 } };

int dist[MAX_VERTICES]; 
int selected[MAX_VERTICES]; 
int parent[MAX_VERTICES]; 

void build_min_heap(HeapType* h)
{
	int i;
	int temp;
	int child;
	int parent;
	for (i = h->heap_size / 2; i >= 1; i--) {
		child = 2 * i;
		parent = i;
		while (child <= h->heap_size) {
			if (child + 1 < h->heap_size && h->heap[child].edge > h->heap[child + 1].edge) {
				child++;
			}
			if (h->heap[parent].edge <= h->heap[child].edge) 
				break;
			temp = h->heap[parent].edge;
			h->heap[parent].edge = h->heap[child].edge;
			h->heap[child].edge = temp;
			parent = child;
			child *= 2;
		}
	}
}
int delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// Find a smaller child node
		if ((child < h->heap_size) &&
			(h->heap[child].edge) > h->heap[child + 1].edge)
			child++;
		if (temp.edge <= h->heap[child].edge) break;
		// Move down one level
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item.vertex;
}
void Decrease_key_min_heap(HeapType* h, int v, int key) {
	int temp;
	int i;
	for (i = 1; i < h->heap_size + 1; i++) {
		if (h->heap[i].vertex == v)
			break;
	}
	h->heap[i].edge = key;
	while ((i != 1) && h->heap[i / 2].edge > h->heap[i].edge) {
		temp = h->heap[i].edge;
		h->heap[i].edge = h->heap[i / 2].edge;
		h->heap[i / 2].edge = temp;
		i = i / 2;
	}

}
void prim(int s) {
	int u, i, v;	
	int input_size = MAX_VERTICES;		
	for (u = 0; u < MAX_VERTICES; u++) { 
		dist[u] = INF;		
		selected[u] = FALSE;		
		parent[u] = NULL; 
	}	
	dist[s] = 0;
	HeapType* minheap = (HeapType*)malloc(sizeof(HeapType));
	// 'heap' is allocated according to 'input_size'.  heap starts with 1, so 'input_size+1' is used.
	minheap->heap = (element*)malloc(sizeof(element) * (input_size + 1));	
	minheap->heap_size = MAX_VERTICES;		
	build_min_heap(minheap);	
	for (int i = 0; i < MAX_VERTICES; i++) { 
		minheap->heap[i + 1].edge = dist[i];		
		minheap->heap[i + 1].vertex = i; 
	}	
	for (i = 0; i < MAX_VERTICES; i++) { 
		u = delete_min_heap(minheap);		
		selected[u] = TRUE;				
		for (v = 0; v < MAX_VERTICES; v++) { 
			if (weight[u][v] != INF) { 
				if (!selected[v] && weight[u][v] < dist[v]) { 
					parent[v] = u;					
					dist[v] = weight[u][v];					
					Decrease_key_min_heap(minheap, v, weight[u][v]); 
				} 
			} 
		} 
	}
}
void print_prim(void) { 
	for (int i = 1; i < MAX_VERTICES; i++) { 
		printf("Vertex %d->%d\tedge: %d\n", parent[i], i, dist[i]); 
	} 
}

int main(void) { 
	prim(8);	
	print_prim(); 
}
