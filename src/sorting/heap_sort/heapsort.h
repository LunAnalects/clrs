#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "macros.h"

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
/*-------------------------------------
*/
#define PARENT(i) (i>>1)
#define LEFT(i) (i<<1)
#define RIGHT(i) ((i<<1)+1)


/*
data structure: max_heap.

size = size of sorted elements.
length = size of arr.
*/

typedef struct heap_array {
	int* arr;
	int length;
	int size;
} heap;


int get_heap_depth(int size);
void print_heap(heap A);
void max_heapify(heap* A, int i);
void build_max_heap(heap* A);
void heapsort(int* array, int n);
int heap_extract_max(heap* A);


#endif
