/*
��rand����������������洢��3����ͬ�������У��������3������
ѡ������ÿ�μ�¼��Сֵ���±꣬������ѵĵ�һ��λ�ý�����
ð������ÿ�μ�¼���һ�ν������±꣬���Ч�ʡ�
����������һ��������temp���飬����ʱ��������
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX_COUNT 21000

int number1[MAX_COUNT];
int number2[MAX_COUNT];
int number3[MAX_COUNT];

bool fwrite(int number[],char* name)    //д���ļ�
{
    FILE *fp;
    if((fp=fopen(name,"w"))==NULL)
        return false;
    for(int i=0;i<MAX_COUNT;++i)
        fprintf(fp,"%d\n",number[i]);
    fclose(fp);
    return true;
}

void sort1()                            //ѡ������
{
    for(int i=0;i<MAX_COUNT-1;i++)
    {
        int minindex=i;                 //��Сֵ�±�
        for(int j=i;j<MAX_COUNT;++j)
            if(number1[minindex]>number1[j])
                minindex=j;
        int temp=number1[i];
        number1[i]=number1[minindex];
        number1[minindex]=temp;
    }
    if(fwrite(number1,"sort_1.txt"))
        printf("ѡ������д��ɹ���\n");
    else
        printf("ѡ������д��ʧ�ܣ�\n");
}

void sort2()                            //ð������
{
    int i=MAX_COUNT-1;
    while(i>0)
    {
        int index=0;                        //��¼���һ�ν������±�
        for(int j=0;j<i;++j)
            if(number2[j]>number2[j+1])
            {
                int temp=number2[j];
                number2[j]=number2[j+1];
                number2[j+1]=temp;
                index=j;
            }
        i=index;
    }
    if(fwrite(number2,"sort_2.txt"))
        printf("ð������д��ɹ���\n");
    else
        printf("ð������д��ʧ�ܣ�\n");
}

void sort3()                               //��������
{
    int temp[MAX_COUNT];
    for(int i=0;i<MAX_COUNT;++i)
    {
        bool last=false;                    //�Ƿ����ĩβ
        for(int j=0;j<i;++j)
            if(number3[i]<temp[j])
            {
                for(int k=i;k>j;--k)
                    temp[k]=temp[k-1];
                temp[j]=number3[i];
                last=true;
                break;
            }
        if(!last)
            temp[i]=number3[i];
    }
    if(fwrite(temp,"sort_3.txt"))
        printf("��������д��ɹ���\n");
    else
        printf("��������д��ʧ�ܣ�\n");
}

int main()
{
    srand((unsigned) time(NULL));       //��ʱ�����֣�ÿ�β����������һ��
    for (int i=0; i<MAX_COUNT; i++)         //����21000����
    {
        number1[i] = number2[i] = number3[i] = rand();             //���������
        printf("%d %d\n",i,number1[i]);
    }
    //sort1();        //ѡ������
    //sort2();        //ð������
    sort3();        //��������
    return 0;
}
