

#include <stdio.h>
#include <stdlib.h>


int* findfirstnumddr(int* p, int length, int delnum)  //寻找数据的存在
{
	//int flag = 0;
	int* pflag = NULL;
	for (int i = 0; i < length; i++)
	{
		if (*(p + i) == delnum)
		{
			pflag = &p[i];   //存在返回下标
			break;
		}
	}
	return pflag;

}
int* findfirstnumddr2(int* p, int length, int delnum)  //寻找数据的存在
{
	//int flag = 0;
	int* pflag = NULL;
	int* pflag2 = NULL;
	for (int i = 0; i < length; i++)
	{
		if (*(p + i) == delnum)
		{
			pflag2 = &p[i];   //存在返回下标
			pflag = pflag2;
			break;
		}
	}
	return pflag;

}
int findfirstnum(int* p, int length, int delnum)  //寻找数据的存在
{
	int flag = -1;
	
	for (int i = 0; i < length; i++)
	{
		if (*(p + i) == delnum)
		{
			flag =i;   //存在返回下标
			break;
		}
	}
	return flag;

}


void deletedata(int** pp,int *plength,int data)
{
	int pos = findfirstnum(*pp, *plength, data);
	if (pos != -1)
	{
		
		for (int i = pos; i < *plength-1; i++)
		{
			(* pp)[i] = ( * pp)[i + 1];  //删除元素就是在元素的位置，接收后面的值
			
			
		}
		*pp = realloc(*pp, sizeof(int) * (*plength - 1));  //压缩空间
		*plength -= 1;
		
	}
	else
	{

		return;
	}

}

void deletedataddr(int** pp, int* plength, int data)
{

	int *pos = findfirstnumddr2(*pp, *plength, data);
	if (*pos != -1)
	{

		for (int i = *pos; i < *plength - 1; i++)
		{
			(*pp)[i] = (*pp)[i + 1];         //删除元素就是在元素的位置，接收后面的值
		}
		*pp = realloc(*pp, sizeof(int) * (*plength - 1));  //压缩空间
		*plength -= 1;

	}
	else
	{

		return;
	}

}

void main()
{
	int* p = malloc(100);
	int length = 0;
	for (int i = 0; i < 25; i++)
	{
		
		if (i % 2 == 0)
		{
			printf("%3d", *(p + i) = 4);
		}
		else
		{
			printf("%3d", *(p + i) = 5);
		}


		length++;
	}
	/*for (int pos = findfirstnum(p, length, 4);pos!=-1;pos=findfirstnum(p,length,4))
	{
		deletedata(&p, &length, 4);
	}*/

	deletedata(&p, &length, 4);
	
	printf("\n\n");
	for (int i = 0; i < length; i++)
	{
		printf("%3d", *(p + i));
	}


	system("pause");
}


void main1()
{
	int* p = malloc(100);
	int length = 0;
	for (int i = 0; i < 25; i++)
	{
		printf("%3d", *(p + i) = i);
		length++;
	}
	
	deletedataddr( &p, &length,20);
	printf("\n\n");
	for (int i = 0; i < length; i++)
	{
		printf("%3d", *(p + i));
	}


	system("pause");
}