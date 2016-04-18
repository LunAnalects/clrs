#include "forward_list.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
typedef struct forward_list list;
typedef struct forward_list_node node;

int main(int argc, char** argv) {

	assert(argc ==2);
	int value = atoi(argv[1]);
	int* arr = (int*)malloc(sizeof(int) * value);
	int randv;
	printf("\nRandNumber:\n");
	int i = 0;
	for (; i < value; ++i) {
		randv = rand() % 100 + 1;
		arr[i] = randv;
		printf("%d\n", randv);
	}
	list* lp = flist_con(5);
	printf("Size after con:%d", flist_size(lp));
	node* np1;
	for (; i > 0; --i) {
		printf("now i :%d,arr[i]:%d\n", i, arr[i - 1]);
		np1 = flist_init_node(arr[i - 1]);
		flist_push_front(lp, np1);
	}
	flist_traverse(lp);


	return 0;
}
