#include "stdafx.h"
#include "dp.h"
/*
*CH15_1
*rod cutting
*/
int* generate_p(int size) {
	int* p = (int*)malloc(sizeof(int)*(size+1));
	int rnd;
	p[0] = 0;
	for (int i = 1; i < size+1; ++i) {
		rnd = rand() % (10+i*5) + i*10 + i*i*100 - i*i*i + 50;
		p[i] = rnd;
		printf("p[length = %d]: ", i);
		printf("%d\n", rnd);
	}
	printf("Generating completed. \n");
	return p;
}

int cur_rod_1(int* p, int n) {
	if (n == 0) return 0;
	int q = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		q = MAX(q, p[i] + cur_rod_1(p, n - i));
	}
	return q;
}

int cur_rod_topdown(int* p, int n) {
	int* r = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i < n; ++i) r[i] = INT_MIN;
	return cur_rod_topdown_aux(p, n, r);
}

int cur_rod_topdown_aux(int* p, int n , int* r) {
	int q;
	if (r[n] >= 0) 
		return r[n];
	if (n == 0)
		q = 0;
	else {
		q = INT_MIN;
		for (int i = 1; i <= n; ++i)
			q = MAX(q, p[i] + cur_rod_topdown_aux(p, n - i, r));
	}
	r[n] = q;
	return q;
}

int cur_rod_bottomup(int* p, int n) {
	int* r = (int*)malloc(sizeof(int)*(n + 1));
	int q;
	r[0] = 0;
	for (int j = 1; j <= n; ++j) {
		q = INT_MIN;
		for (int i = 1; i <= j; ++i) 
			q = MAX(q, p[i] + r[j - i]);
		r[j] = q;
	}
	return r[n];
}

int extended_cur_rod_bottomup(int* p, int n) {
	int* r = (int*)malloc(sizeof(int)*(n + 1));
	int* s = (int*)malloc(sizeof(int)*(n + 1));
	int q;
	int cut = 0;
	r[0] = 0;
	s[0] = 0;
	for (int j = 1; j <= n; ++j) {
		q = INT_MIN;
		for (int i = 1; i <= j; ++i) {
			if (q < p[i] + r[j - i]) {
				cut = i;
				q =  p[i] + r[j - i];
			}
		}
		r[j] = q;
		s[j] = cut;
	}
	printf("The optimal cutting method:\n");
	int i = n;
	while (i) {
		printf("%d || ", s[i]);
		i = i-s[i];
	}
	printf("\n\n");
	printf("s[n]:");
	for (int i = 0; i < n + 1; ++i) {
		printf("%d	", s[i]);
	}
	printf("\n\n");
	return r[n];
}

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

