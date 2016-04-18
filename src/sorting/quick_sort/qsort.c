#include "qsort.h"

int partition(int* A, int size) {
	int pivot = A[size - 1];
	int i = 0;
	for (int j = 1; j < size; ++j) {
		if (A[j - 1] <= pivot) {
			++i;
			swap(A[j - 1], A[i - 1]);
		}
	}
	swap(A[size - 1], A[i]);
	return i + 1;
}

int randomized_partition(int* A, int size) {
	int i = rand() % size;
	swap(A[size - 1], A[i]);
	return partition(A, size);
}

void randomized_qsort(int* A, int size) {
	if (size > 1) {
		int q = randomized_partition(A, size);
		randomized_qsort(A, q - 1);
		randomized_qsort(A + q, size - q);
	}
}
