// program_prictice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define  MAXSIZE 50
typedef char  ElemType;
typedef struct 
{
	ElemType *top;      //栈顶指针
	int size;			//当前栈中元素个数
	ElemType *base;     //栈底指针
}Stack;

void Stack_Init(Stack *S)
{
	S->base = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	S->top = S->base;
	S->size = 0;
}

/************************************************************************/
/* 功能：判断是否栈满
   参数：栈指针
   返回值：栈满为false，否则true*/
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
/* 功能：判断栈是否为空
   参数：栈指针
   防回值：为空返回false，否则返回true*/
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
/* 功能：将一个元素入栈
   参数：栈指针，待入栈元素
   返回值：入栈成功返回true，否则返回false
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
/* 功能：将元素出栈
   参数：栈指针，存放出栈元素的指针
   返回值：出栈成功返回true，否则返回false*/
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
/* 功能：将一个字符转化成十进制数字
   参数：待转换的字符
   返回值：转换后的十进制数字*/
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


/* 功能：将一个数字转换成其他进制表示时对应的字母
   参数：待转换的整数
   返回结果：转换后的字母*/
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
/* 功能：检查输入是否合法
   参数：输入的数及进制
   返回值：合法返回true，否则返回false*/
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
/* 功能：整数的指数运算
   参数：底数，指数
   返回值：返回运算结果*/
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
/* 功能：将一个其他进制的数转化成十进制的数
   参数：非十进制数，该数的进制
   返回值：返回十进制的数*/
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
/* 功能：将一个十进制的数转换成 其他进制的数并输出
   参数：十进制长整数，需要转换的进制,栈指针
   返回值：无*/
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
	char data[100];int M,MO;			//数的大小及该数的进制
	long decimal_retval;
	printf("请输入一个数，如B8(字母需大写）:");
	scanf_s("%s",data,100);
	getchar();
	printf("请输入进制，如16:");
	scanf_s("%d",&M);
	printf("请输入要转换的进制：");
	scanf_s("%d",&MO);
	
	//对输入的数进行合法性检查
	while(!IsInputLegal(data,M,MO))
	{
		printf("输入不合法，请重新输入！\n");
		printf("请输入一个数，如B8(字母需大写）:");
		scanf_s("%s",data,100);
		getchar();
		printf("请输入进制，如16:");
		scanf_s("%d",&M);
		printf("请输入要转换的进制：");
		scanf_s("%d",&MO);
		
	}


	decimal_retval = GetDecimal(data,M);
	printf("十进制数值为：%d\n",decimal_retval);
	char *ret;
	printf("转换后的结果为：\n");
	GetOtherSystem(decimal_retval,MO);
	
	return 0;
}

