

#include <stdio.h>
#include <stdlib.h>


void show1()
{
	int* p = malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", p[i] = i);
	}
	free(p);
	p = NULL;
}
void show2()
{
	int** pp = malloc(sizeof(int*) * 10);
	for (int i = 0; i < 10; i++)
	{
		pp[i] = malloc(sizeof(int) * 10);
		printf("%p\n%16s", pp[i]," ");
		for (int j = 0; j < 10; j++)
		{
			printf(" %4d", pp[i][j] = i * 10 + j);
		}
		printf("\n");
	}



}

void show3()
{
	int*** ppp = malloc(sizeof(int**) * 10);
	for (int i = 0; i < 10; i++)
	{
		ppp[i] = malloc(sizeof(int*) * 10);
		printf("%8p\n", ppp[i]);
		for (int j = 0; j < 10; j++)
		{
			ppp[i][j] = malloc(sizeof(int) * 10);
			printf("%32p\n%32s", ppp[i][j]," ");
			for (int k = 0; k < 10; k++)
			{
				printf("%5d", ppp[i][j][k] = i * 100 + j * 10 + k);
			}
			printf("\n");

		}
		printf("\n\n");
	}



}


void main()
{
	//show1();
	//show2();
	show3();

	system("pause");
}