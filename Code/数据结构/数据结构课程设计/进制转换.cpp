// program_prictice.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define  MAXSIZE 50
typedef char  ElemType;
typedef struct 
{
	ElemType *top;      //ջ��ָ��
	int size;			//��ǰջ��Ԫ�ظ���
	ElemType *base;     //ջ��ָ��
}Stack;

void Stack_Init(Stack *S)
{
	S->base = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	S->top = S->base;
	S->size = 0;
}

/************************************************************************/
/* ���ܣ��ж��Ƿ�ջ��
   ������ջָ��
   ����ֵ��ջ��Ϊfalse������true*/
/************************************************************************/
bool Stack_Full(Stack *S)
{
	if (MAXSIZE == S->top-S->base)
	{
		return false;
	}
	else
		return true;
}

/************************************************************************/
/* ���ܣ��ж�ջ�Ƿ�Ϊ��
   ������ջָ��
   ����ֵ��Ϊ�շ���false�����򷵻�true*/
/************************************************************************/
bool Stack_Empty(Stack *S)
{
	if (S->base == S->top)
	{
		return false;
	}
	else
		return true;
}

/************************************************************************/
/* ���ܣ���һ��Ԫ����ջ
   ������ջָ�룬����ջԪ��
   ����ֵ����ջ�ɹ�����true�����򷵻�false
   */
/************************************************************************/
bool Push(Stack *S,ElemType e)
{
	if (!Stack_Full(S))
	{
		return false;
	}
	*S->top++ = e;
	S->size++;
	return true;
}

/************************************************************************/
/* ���ܣ���Ԫ�س�ջ
   ������ջָ�룬��ų�ջԪ�ص�ָ��
   ����ֵ����ջ�ɹ�����true�����򷵻�false*/
/************************************************************************/
bool Pop(Stack *S,ElemType *e)
{
	if (!Stack_Empty(S))
	{
		return false;
	}
	*e = *--S->top;
	return true;
}


/************************************************************************/
/* ���ܣ���һ���ַ�ת����ʮ��������
   ��������ת�����ַ�
   ����ֵ��ת�����ʮ��������*/
/************************************************************************/
int GetNumber(char s)
{
	int res;
	if (s>='0'&&s<='9')
	{
		res = s-'0';
	}
	else
	{
		res = s - 'A'+10;
	}
	return res;
}
/************************************************************************/


/* ���ܣ���һ������ת�����������Ʊ�ʾʱ��Ӧ����ĸ
   ��������ת��������
   ���ؽ����ת�������ĸ*/
/************************************************************************/
char GetChar(int d)
{
	if (d<10)
	{
		return ('0'+d);
	}
	else
	{
		return ('A'-10+d);
	}
}

/************************************************************************/
/* ���ܣ���������Ƿ�Ϸ�
   �������������������
   ����ֵ���Ϸ�����true�����򷵻�false*/
/************************************************************************/
bool IsInputLegal(char data[],int M,int MO)
{

	if (M<2 || M>36 || MO<2 ||MO>36)
	{
		return false;
	}
	for (int i=0;data[i]!='\0';++i)
	{
		if (!(data[i]>='0'&&data[i]<='9' || data[i]>='A'&&data[i]<='Z'))
		{
			return false;
			
		}
		if (data[i]>=GetChar(M))
		{
			return false;
		}
	}
	return true;
}

/************************************************************************/
/* ���ܣ�������ָ������
   ������������ָ��
   ����ֵ������������*/
/************************************************************************/
long mypow(int d,int s)
{
	long res=1;
	for (int i=0;i<s;++i)
	{
		res = res*d;
	}
	return res;
}

/************************************************************************/
/* ���ܣ���һ���������Ƶ���ת����ʮ���Ƶ���
   ��������ʮ�������������Ľ���
   ����ֵ������ʮ���Ƶ���*/
/************************************************************************/
long GetDecimal(char data[],int M)
{
	long sum = 0,k=0;
	for (int i=strlen(data)-1;i>=0;--i)
	{
		sum = sum + GetNumber(data[k])*mypow(M,i);
		++k;
	}
	return sum;
}

/************************************************************************/
/* ���ܣ���һ��ʮ���Ƶ���ת���� �������Ƶ��������
   ������ʮ���Ƴ���������Ҫת���Ľ���,ջָ��
   ����ֵ����*/
/************************************************************************/
void *GetOtherSystem(long decimal,int M)
{
	int n;
	Stack S;
	char ret[100];
	Stack_Init(&S);
	while (decimal!=0)
	{
		n=decimal % M;
		if(!Push(&S,GetChar(n)))
			return NULL;
		decimal /= M;
	}
	int i;
	for(i=0;i<S.size;++i)
	{
		if (!Pop(&S,&ret[i]))
		{
			return NULL;
		}
	}
	ret[i] = '\0';
	printf("%s\n",ret);
}
int _tmain(int argc, _TCHAR* argv[])
{
	char data[100];int M,MO;			//���Ĵ�С�������Ľ���
	long decimal_retval;
	printf("������һ��������B8(��ĸ���д��:");
	scanf_s("%s",data,100);
	getchar();
	printf("��������ƣ���16:");
	scanf_s("%d",&M);
	printf("������Ҫת���Ľ��ƣ�");
	scanf_s("%d",&MO);
	
	//������������кϷ��Լ��
	while(!IsInputLegal(data,M,MO))
	{
		printf("���벻�Ϸ������������룡\n");
		printf("������һ��������B8(��ĸ���д��:");
		scanf_s("%s",data,100);
		getchar();
		printf("��������ƣ���16:");
		scanf_s("%d",&M);
		printf("������Ҫת���Ľ��ƣ�");
		scanf_s("%d",&MO);
		
	}


	decimal_retval = GetDecimal(data,M);
	printf("ʮ������ֵΪ��%d\n",decimal_retval);
	char *ret;
	printf("ת����Ľ��Ϊ��\n");
	GetOtherSystem(decimal_retval,MO);
	
	return 0;
}

