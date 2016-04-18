#ifndef CLRS_STACK_H
#define CLRS_STACK_H
#include "stdlib.h"
#include "stdio.h"

struct Stack {
	int size;
	int top;
	int* arr;
};

void stack_init(struct Stack* s, int size);
int stack_empty(struct Stack* s);
void stack_push(struct Stack* s, int e);
int stack_pop(struct Stack* s);
void stack_delete(struct Stack* s);

#endif
