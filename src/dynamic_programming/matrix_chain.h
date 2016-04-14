#ifndef CLRS_DYNAMIC_PROGRAMMING_MATRIX_CHAIN_H
#define CLRS_DYNAMIC_PROGRAMMING_MATRIX_CHAIN_H
#define MAX(a,b) ((a>b)?a:b)
#include <stdlib.h>
#include <stdio.h>
//CH15.2
typedef struct matrix {
	size_t col;
	size_t row;
	int **m;
}matrix, *mptr;
mptr matrix_init(size_t row, size_t col, int val);
mptr *matrixArray_init(size_t *p, size_t pSize, int val);
void matrix_print(mptr m);
mptr matrix_multiply(mptr a, mptr b);
void matrix_parenthesization(mptr *matrixArray, size_t *p, size_t pValue);
#endif // CLRS_DYNAMIC_PROGRAMMING_MATRIX_CHAIN_H