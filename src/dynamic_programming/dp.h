#ifndef CLRS_DP_H
#define CLRS_DP_H
#define MAX(a,b) ((a>b)?a:b)
#include <stdlib.h>
#include <stdio.h>
//CH15.1
int* generate_p(int size);
int cur_rod_1(int* p, int n);
int cur_rod_topdown(int* p, int n);
int cur_rod_topdown_aux(int* p, int n, int* r);
int cur_rod_bottomup(int* p, int n);
int extended_cur_rod_bottomup(int* p, int n);

//CH15.2
typedef struct matrix {
	size_t col;
	size_t row;
	int** m;
}matrix, *mptr;
mptr matrix_init(size_t row, size_t col, int val);
void matrix_print(mptr m);
mptr matrix_multiply(mptr a, mptr b);
#endif // CLRS_DP_H