#include "heapsort.h"
/*
THESE functions are not from CLRS.

To print out the architect of a heap
*/
int get_heap_depth(int size)
{	
	if(size ==0) return 0;
	if(size ==1) return 1;
	int depth = 0;
	while(!(size&0x8000))
	{
		size =size<<1;
		++depth;
	}
	return 16-depth;
}
void print_heap(heap A)
{
	if (A.size=0)
		return;

	int* array = A.arr;
	int size = A.size;
	int depth = get_heap_depth(size);

	int line_size = (2<<(depth-1))*3;

	char* line = (char*)malloc(line_size);

	for(int i = 0;i<depth;++i)
	{
		//Todo
	}

}
/*
from pseudocode in CLRS 6.2
it assumes the subtree rooted at LEFT(i) and RIGHT(i) are already max-heaps.

O(lgn)
i is the 1-based position of element, not 0-based index!
*/
void max_heapify(heap* A, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);

	int largest = (l <= A->size && A->arr[l-1] >A->arr[i-1])?l:i;
	if(r<=A->size && A->arr[r-1]>A->arr[largest-1])
		largest = r;

	if(largest != i)
	{
		swap(A->arr[i-1],A->arr[largest-1]);
		max_heapify(A,largest);
	}

}
/*
from pseudocode in CLRS 6.3
Every element in the later half, starting from A.atrr[(n/2)+1], is 1-element heap.
So build_max_heap only needs go through the first half.
*/
void build_max_heap(heap* A)
{
	A->size = A->length;
	for(int i =A->length/2;i>0;--i)
	{
		max_heapify(A,i);
	}
}
/*
from pseudocode in CLRS 6.4
*/
void heapsort(int* array,int n)
{
	heap h;
	heap* A = &h;
	A->length = n;
	A->size = 0;
	A->arr = array;
	build_max_heap(A);
	for(int i = A->length;i>1;--i)
	{
		swap(A->arr[0],A->arr[i-1]);
		--A->size;
		max_heapify(A,1);
	}
}
/*Prior Queue 6.5
No heap underflow error,don't pass null heap!
*/
int heap_extract_max(heap* A)
{
	int max = A->arr[0];
	A->arr[0]=A->arr[A->size-1];
	--A->size;
	max_heapify(A,1);
}

void heap_increase_key(heap* A, int n, int key)
{
	if(key<A[n-1])
	{
		return;
	}
	A[n-1] = key;
	while(key >A[PARENT[n]-1] &&n>1)
	{
		swap(A[PARENT[n]-1],A[n-1]);
		n=PARENT[n];
	}
}