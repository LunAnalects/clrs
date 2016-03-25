#include "heapsort.h"
#include "assert.h"
int main(int argc, char** argv)
{
	
	assert(argc ==2);
	int value = atoi(argv[1]);

	int randv;

	heap* hp = (heap*)malloc(sizeof(hp));
	hp->arr = (int*)malloc(sizeof(int)*value);
	hp->size = value;
	hp->length = value;

	for(int i =0;i<hp->size;++i)
	{
		randv = rand()%100+1;
		hp->arr[i] = randv;
		printf("%d\n",randv);
	}
	printf("\nSorted:\n");

	heapsort(*hp);

	for(int i =0;i<hp->size;++i)
		printf("%d\n",hp->arr[i]);
	return 0;
}