#ifndef CLRS_DYNAMIC_PROGRAMMING_CUT_ROD_H
#define CLRS_DYNAMIC_PROGRAMMING_CUT_ROD_H
#define MAX(a,b) ((a>b)?a:b)
#include <stdlib.h>
#include <stdio.h>
//CH15.1
int* generate_p(int size);
int cur_rod_1(int* p, int n);
int cur_rod_topdown(int* p, int n);
int cur_rod_topdown_aux(int* p, int n, int* r);
int cur_rod_bottomup(int* p, int n);
int extended_cur_rod_bottomup(int* p, int n, int* s);
void cut_rod_method_print(int* s, int n);


#endif // CLRS_DYNAMIC_PROGRAMMING_CUT_ROD_H
