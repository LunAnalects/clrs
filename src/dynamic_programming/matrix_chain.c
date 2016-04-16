#include "matrix_chain.h"
/*CH15_2
* Matrix-chain multiplication
*/

/*CH15_2
* Matrix-chain multiplication
*/

mptr matrix_init(int row, int col, int val) {
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

mptr *matrixArray_init(int *p, int pSize, int val) {
	mptr * matrixArray = (mptr *)malloc(sizeof(mptr)*(pSize - 1));
	for (int c = 1; c < pSize; ++c)
		matrixArray[c - 1] = matrix_init(p[c - 1], p[c], val);
	return matrixArray;
}

void matrix_print(mptr m) {
	int row = m->row;
	int col = m->col;
	printf("A %d X %d MATRIX:\n", row, col);
	for (int i = 0; i < row; ++i) {
		printf("row %.5d:    ", i + 1);
		for (int j = 0; j < col; ++j) {
			printf("%.3d  ", m->m[i][j]);
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
//return int *p, length = size+1
int* get_rc(mptr *matrixArray, int size) {
	int *p = (int*)malloc(sizeof(int)*(size + 1));
	p[0] = matrixArray[0]->row;
	p[size] = matrixArray[size - 1]->col;
	for (int i = 1; i < size ; ++i)
		p[i] = matrixArray[i]->row;
	return p;
}
int multi3(int p1, int p2, int p3) {
	return p1 * p2 * p3;
}
/*top-down Method
*/
int topdown(int i, int j, mptr flag_matrix, int *p) {
	int opt_time = INT_MAX;
	int left_time = 0;
	int right_time = 0;
	int new_time = 0;
	if (j - i == 1) return 0;
	else if (j - i == 2) {
		flag_matrix->m[i][j] = multi3(p[i], p[i + 1], p[j]);
		return flag_matrix->m[i][j];
	}
	else {
		for (int k = i + 1; k < j; ++k) {
			right_time = topdown(k, j, flag_matrix, p);
			left_time = topdown(i, k, flag_matrix, p);
			new_time = multi3(p[i], p[k], p[j]) + left_time + right_time;
			if (opt_time > new_time) {
				opt_time = new_time;
				flag_matrix->m[i][j] = opt_time;
				flag_matrix->m[j][i] = k;
			}
		}
	}
	return flag_matrix->m[i][j];
}

int matrix_parenthesization_topdown(mptr *matrixArray, int size, mptr mk) {
	int *p = get_rc(matrixArray, size);
	int number = topdown(0, size, mk, p);
	free(p);
	return number;
}

void matrix_print_optim(mptr* matrixArray, int size, mptr mk) {
	int **ma = mk->m;
	int *p = get_rc(matrixArray, size);
	print_recursive(ma, p, 0, size);
	printf("\n");
}

void print_recursive(int** mk,int* p, int begin, int end) {
	if (end - begin == 1) {
		printf(" [%d X %d] ", p[begin], p[begin + 1]);
	}
	else if (end - begin == 2) {
		printf(" [%d X %d]  [%d X %d] ", p[begin], p[begin + 1], p[begin + 1], p[begin + 2]);
	}
	else {
		int k = mk[end][begin];
		printf(" (");
		print_recursive(mk,p, begin, k);
		print_recursive(mk,p, k, end);
		printf(") ");
	}
}

/*bottom-up Method
*/

int matrix_parenthesization_bottomup(mptr *matrixArray, int size, mptr flag_matrix) {
	int** matrix = flag_matrix->m;
	int newtime;
	int time = -1;
	int *p = get_rc(matrixArray, size);
	for (int i = 0; i < size - 1; ++i) 
		matrix[i][i + 2] = multi3(p[i], p[i + 1], p[i + 2]);
	//k is the size of sub-matrixArray
	for (int k = 3; k < size + 1; ++k) {
		for (int i = 0; i < size - k + 1; ++i) {
			for (int j = i + 1; j < i+k; ++j) {
				newtime = matrix[i][j] +matrix[j][i + k] + multi3(p[i], p[j], p[i + k]);
				if (time <= 0 || time > newtime) {
					time = newtime;
					matrix[i + k][i] = j;
				}
			}
			matrix[i][i + k] = time;
			time = -1;
		}
	}
	free(p);
	return matrix[0][size];
}
/*Matrix array multiplication using bottom up method to optimize sequence.
*Optimized sequence info is stored in flag matrix, and then do multilication recursively according to te sequence.
*/
mptr matrixArray_multipy(mptr* matrixArray, int size) {
	mptr flag_matrix = matrix_init(size + 1, size + 1, 0);
	matrix_parenthesization_bottomup(matrixArray, size, flag_matrix);
	return multiply_recursive(matrixArray, 0, size, flag_matrix);
}

mptr multiply_recursive(mptr *ma, int b, int e, mptr flag) {
	if (e - b == 1) return ma[b];
	else if (e - b == 2) return matrix_multiply(ma[b], ma[b+1]);
	else {
		mptr lm = multiply_recursive(ma, b, flag->m[e][b], flag);
		mptr rm = multiply_recursive(ma, flag->m[e][b], e, flag);
		mptr result =  matrix_multiply(lm, rm);
		free(lm);
		free(rm);
		return result;
	}
}