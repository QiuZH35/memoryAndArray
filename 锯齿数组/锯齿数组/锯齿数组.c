

#include <stdio.h>
#include <stdlib.h>

#define N 10




void main()
{
	int* p = malloc(sizeof(int) * N);  //p[5]
	int** pp = malloc(sizeof(int*) *( 2*N-1)); // pp[2*N-1]
	for (int i = 0; i < N; i++)
	{
		pp[i] = malloc(sizeof(int) * (N - i));

		for (int j = 0; j < N-i; j++)
		{
			printf("%4d", *(*(pp + i) + j) = j + 1);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = N; i < 2 * N - 1; i++)   //在原有的pp后面分配空间
	{

		pp[i] = malloc(sizeof(int) * (i - N + 2));
		for (int j = 0; j <i-N+2; j++)
		{
			printf("%4d", *(*(pp + i) + j) = j + 1);
		}
		printf("\n");
	}



	system("pause");
}