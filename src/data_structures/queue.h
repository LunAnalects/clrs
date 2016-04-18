#ifndef CLRS_QUEUE_H
#define CLRS_QUEUE_H
#include "stdlib.h"
#include "stdio.h"

struct Queue {
	int size;
	int head;
	int tail;
	int* arr;
};

void queue_init(struct Queue* q, int size);
void queue_delete(struct Queue* q);
void queue_enqueue(struct Queue* q, int e);
int queue_dequeue(struct Queue* q);


#endif
