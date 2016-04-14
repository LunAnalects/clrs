#include "matrix_chain.h"
/*CH15_2
* Matrix-chain multiplication
*/

mptr matrix_init(size_t row, size_t col,int val) {
	mptr c = (mptr)malloc(sizeof(matrix));
	c->row = row;
	c->col = col;
	c->m = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < c->row; ++i) {
		c->m[i] = (int*)malloc(sizeof(int)*c->col);
		for (int j = 0; j < c->col; ++j)
			c->m[i][j] = val;
	}
	return c;
}

mptr *matrixArray_init(size_t *p,size_t pSize, int val){
	mptr * matrixArray = (mptr *)malloc(sizeof(mptr)*(pSize-1));
	for(int c = 1; c < pSize; ++c)
		matrixArray[c-1] = matrix_init(p[c-1], p[c], val);
	return matrixArray;
}

void matrix_print(mptr m) {
	int row = m->row;
	int col = m->col;
	printf("a %d X %d MATRIX:\n", row, col);
	for (int i = 0; i < row; ++i) {
		printf("column %.3i:    ",i+1);
		for (int j = 0; j < col; ++j) {
			printf("%.3i  ", m->m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

mptr matrix_multiply(mptr a, mptr b) {
	if (a->col != b->row)
		return NULL;
	mptr c = matrix_init(a->row, b->col, 0);
	for (int i = 0; i < a->row; ++i) {
		for (int j = 0; j < b->col; ++j) {
			for (int k = 0; k < a->col; ++k) {
				c->m[i][j] += a->m[i][k] * b->m[k][j];
			}
		}
	}
	return c;
}

void matrix_parenthesization(mptr *matrixArray, size_t *p, size_t pValue){
	
}