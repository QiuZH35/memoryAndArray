

#include <stdio.h>
#include <stdlib.h>



int* add(int* p, int num)   //副本机制
{
	p[24] = num;

	return p;
}



//改变一个指针的值，需要用上二级指针
void addp(int** pp, int num)  //有可能修改p,p是副本
{
	*pp = realloc(*pp,104);//内存开辟

	(* pp)[25] = num;  //[]的优先级大于*

}


void main()
{
	int* p = malloc(100);
	for (int i = 0; i < 25; i++)
	{
		printf("\n%d", *(p+i) = i);
	}

	//p = add(p, 100); //指针返回值修改


	addp(&p, 100);
	for (int i = 0; i < 26; i++)
	{
		printf("\n%d", *(p + i));
	}



	system("pause");
}