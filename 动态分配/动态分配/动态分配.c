

#include <stdio.h>
#include <stdlib.h>



int* add(int* p, int num)   //��������
{
	p[24] = num;

	return p;
}



//�ı�һ��ָ���ֵ����Ҫ���϶���ָ��
void addp(int** pp, int num)  //�п����޸�p,p�Ǹ���
{
	*pp = realloc(*pp,104);//�ڴ濪��

	(* pp)[25] = num;  //[]�����ȼ�����*

}


void main()
{
	int* p = malloc(100);
	for (int i = 0; i < 25; i++)
	{
		printf("\n%d", *(p+i) = i);
	}

	//p = add(p, 100); //ָ�뷵��ֵ�޸�


	addp(&p, 100);
	for (int i = 0; i < 26; i++)
	{
		printf("\n%d", *(p + i));
	}



	system("pause");
}