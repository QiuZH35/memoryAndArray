

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num;


 
void init(char*** ppp,int num)    //�ı�ָ���ֵ����Ҫָ��ĵ�ַ
{
	
	
	(*ppp) = malloc(sizeof(char*) *num);    //ppp�������Ƕ���ָ�� ��(*ppp)[num]
	for (int i = 0; i < num; i++)
	{
		char str[1024] = { 0 };
		scanf("%s", str);
		(* ppp)[i] = malloc(sizeof(char) * (strlen(str) + 1));
		strcpy((*ppp)[i], str);

	}
	for (int i = 0; i < num; i++)
	{
		printf("\n%s",(* ppp)[i]);     //ȡ��ppp��ֵ��ppp��һ������ָ�룬ȡֵ��Ҫ����* ����*ppp)[i]
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
			printf("�ҵ���%p ,%s\n", pp[zhong], pp[zhong]);
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


void sort(char** pp,int num)      //�ı�ָ��ָ��ı�������Ҫָ���ֵ
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
	printf("\n���ݲ�\n");

	for (int i = 0; i < num; i++)
	{
		printf("%s\n", pp[i]);
	}

	printf("���ֲ���\n");
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
			printf("\n�ҵ���%p,%s",(* ppp)[zhong],(* ppp)[zhong]);
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
		ppp[i] = &pp[i];      //��Ŷ���ָ������ݣ��൱�ڿ���һ��
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
	printf("\n����ָ���������ʾ��\n");
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", *ppp[i]);
	}
	printf("\n���ݲ�\n");

	for (int i = 0; i < num; i++)
	{
		printf("%s\n", pp[i]);
	}
	printf("\n\n���ֲ���\n");
	
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
			printf("\n�ҵ���%p,%s", (*ppp)[zhong],(* ppp)[zhong]);
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
	init(&pp,num);  //�ı�ָ���ֵ

	sort(pp,num); //�ı�ָ��ָ��ı���
	//sortbyaddr(pp);

	
	system("pause");
}











void main1()
{
	int num;
	scanf("%d", &num);//����һ���ռ�Ϊnum��ָ������
	char** pp = malloc(sizeof(char*) * num);//(*pp)[num];

	for (int i = 0; i < num; i++)
	{
		char str[1024] = { 0 };
		scanf("%s", str);    //��������
		pp[i] = malloc(sizeof(char) * (strlen(str) + 1));
		strcpy(pp[i], str);//����

	}
	for (int i = 0; i < num; i++)
	{
		printf("\n%s", pp[i]);
	}




	system("pause");
}