#include "stack.h"

void stack_init(struct Stack* s,int size){
	s->size = size;
	s->arr = malloc(sizeof(int)*size);
	s->top = 0;
}

int stack_empty(struct Stack* s){
	return s->top == 0;
}
void stack_push(struct Stack* s, int e){
	s->arr[s->top] = e;
	++ s->top;
}
int stack_pop(struct Stack* s){
	-- s->top;
	return s->arr[s->top];
}

void stack_delete(struct Stack* s){
	free(s->arr);
}