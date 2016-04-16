#ifndef CLRS_DYNAMIC_PROGRAMMING_MATRIX_CHAIN_H
#define CLRS_DYNAMIC_PROGRAMMING_MATRIX_CHAIN_H
#define MAX(a,b) ((a>b)?a:b)
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
//CH15.2//CH15.2
typedef struct matrix {
	int col;
	int row;
	int **m;
}matrix, *mptr;
mptr matrix_init(int row, int col, int val);
mptr *matrixArray_init(int *p, int pSize, int val);
void matrix_print(mptr m);
mptr matrix_multiply(mptr a, mptr b);
int* get_rc(mptr *matrixArray, int size);
int multi3(int p1, int p2, int p3);
int topdown(int i, int j, mptr mk, int *p);
int matrix_parenthesization_topdown(mptr *matrixArray, int size, mptr mk);
int matrix_parenthesization_bottomup(mptr *matrixArray, int size, mptr flag_matrix);
void print_recursive(int** mk, int* p, int begin, int end);
void matrix_print_optim(mptr* matrixArray, int size, mptr mk);
mptr matrixArray_multipy(mptr* matrixArray, int size);
mptr multiply_recursive(mptr *ma, int b, int e, mptr flag);
#endif // CLRS_DYNAMIC_PROGRAMMING_MATRIX_CHAIN_H