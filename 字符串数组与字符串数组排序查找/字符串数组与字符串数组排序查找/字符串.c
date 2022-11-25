

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num;


 
void init(char*** ppp,int num)    //改变指针的值，需要指针的地址
{
	
	
	(*ppp) = malloc(sizeof(char*) *num);    //ppp操作的是二级指针 ，(*ppp)[num]
	for (int i = 0; i < num; i++)
	{
		char str[1024] = { 0 };
		scanf("%s", str);
		(* ppp)[i] = malloc(sizeof(char) * (strlen(str) + 1));
		strcpy((*ppp)[i], str);

	}
	for (int i = 0; i < num; i++)
	{
		printf("\n%s",(* ppp)[i]);     //取出ppp的值，ppp是一个三级指针，取值需要加上* ，（*ppp)[i]
	}


}

void sortsearch(char** pp)
{
	char searchstr[100] = { 0 };
	scanf("%s", searchstr);
	int tou = 0;
	int wei = num - 1;
	int zhong;
	while (tou <= wei)
	{
		zhong = (tou + wei) / 2;
		if (strcmp(pp[zhong], searchstr) == 0)
		{
			printf("找到了%p ,%s\n", pp[zhong], pp[zhong]);
			break;
		}
		else
			if (strcmp(pp[zhong], searchstr) > 0)
			{
				wei = zhong - 1;
			}
			else
			{
				tou = zhong + 1;
			}




	}

}


void sort(char** pp,int num)      //改变指针指向的变量，需要指针的值
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (strcmp(pp[j], pp[j + 1]) > 0)
			{
				char* temp = pp[j];
				pp[j] = pp[j + 1];
				pp[j + 1] = temp;
			}
		}
	}
	printf("\n数据层\n");

	for (int i = 0; i < num; i++)
	{
		printf("%s\n", pp[i]);
	}

	printf("二分查找\n");
	sortsearch(pp);



}



void sortbyaddrsearch(char*** ppp)
{
	char searchstr[100] = { 0 };
	scanf("%s", searchstr);
	int tou = 0;
	int wei = num - 1;
	int zhong;
	while (tou <= wei)
	{
		zhong = (tou + wei) / 2;
		if (strcmp((*ppp)[zhong], searchstr)==0)
		{
			printf("\n找到了%p,%s",(* ppp)[zhong],(* ppp)[zhong]);
			break;
		}
		else
			if (strcmp((*ppp)[zhong], searchstr) > 0)
			{
				wei = zhong - 1;
			}
			else
			{

				tou = zhong + 1;

			}

	}

}


void sortbyaddr(char** pp)    
{
	char*** ppp = malloc(sizeof(char**) * num);    
	for (int i = 0; i < num; i++)
	{
		ppp[i] = &pp[i];      //存放二级指针的数据，相当于拷贝一份
	}
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (strcmp(*ppp[j], *ppp[j + 1]) > 0)
			{
				char** pptemp = ppp[j];
				ppp[j] = ppp[j + 1];
				ppp[j + 1] = pptemp;
			}
		}
	}
	printf("\n二级指针数组的显示层\n");
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", *ppp[i]);
	}
	printf("\n数据层\n");

	for (int i = 0; i < num; i++)
	{
		printf("%s\n", pp[i]);
	}
	printf("\n\n二分查找\n");
	
	//sortbyaddrsearch(ppp);
	char searchstr[100] = { 0 };
	scanf("%s", searchstr);
	int tou = 0;
	int wei = num - 1;
	int zhong;
	while (tou <= wei)
	{
		zhong = (tou + wei) / 2;
		if (strcmp((*ppp)[zhong],searchstr)==0)
		{
			printf("\n找到了%p,%s", (*ppp)[zhong],(* ppp)[zhong]);
			break;
		}
		else 
			if (strcmp((*ppp)[zhong], searchstr) > 0)
			{
				wei = zhong - 1;
			}
			else
			{

				tou = zhong + 1;

			}

	}


}





void main()
{
	
	scanf("%d",&num);
	char** pp;
	init(&pp,num);  //改变指针的值

	sort(pp,num); //改变指针指向的变量
	//sortbyaddr(pp);

	
	system("pause");
}











void main1()
{
	int num;
	scanf("%d", &num);//创建一个空间为num的指针数组
	char** pp = malloc(sizeof(char*) * num);//(*pp)[num];

	for (int i = 0; i < num; i++)
	{
		char str[1024] = { 0 };
		scanf("%s", str);    //接受输入
		pp[i] = malloc(sizeof(char) * (strlen(str) + 1));
		strcpy(pp[i], str);//拷贝

	}
	for (int i = 0; i < num; i++)
	{
		printf("\n%s", pp[i]);
	}




	system("pause");
}