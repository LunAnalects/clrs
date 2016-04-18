#include "queue.h"

void queue_init(struct Queue* q, int size) {
	q->size = size;
	q->head = 0;
	q->tail = 0;
	q->arr = malloc(sizeof(int) * size);
}

void queue_delete(struct Queue* q) {
	free(q->arr);
}

void queue_enqueue(struct Queue* q, int e) {
	q->arr[q->tail] = e;
	q->tail = (q->tail == q->size - 1) ? 0 : q->tail + 1;
}

int queue_dequeue(struct Queue* q) {
	int r = q->arr[q->head];
	q->head = (q->head == q->size - 1) ? 0 : q->head + 1;
	return r;
}
