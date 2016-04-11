#include "qsort.h"
#include "assert.h"
int main(int argc, char** argv)
{
	
	assert(argc ==2);
	int value = atoi(argv[1]);

	int randv;
	int* arr = (int*)malloc(sizeof(int)*value);

 	printf("\nRandNumber:\n"); 
	for(int i =0;i<value;++i)
	{
		randv = rand()%100+1;
		arr[i] = randv;
		printf("%d\n",randv);
	}

	int i =partition(arr,value);
	printf("pivot:%d",i);
 	printf("\npartition:\n");   
	for(int i =0;i<value;++i)
	{
		printf("%d\n",arr[i]);
	}


	randomized_qsort(arr,value);
	printf("\nSorted:\n");   
	for(int i =0;i<value;++i)
	{
		printf("%d\n",arr[i]);
	}



	//free((void*)arr);
	return 0;
}