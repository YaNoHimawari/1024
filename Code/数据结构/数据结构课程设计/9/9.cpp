/*
用rand函数生成随机数，存储在3个相同的数组中，方便进行3次排序。
选择排序每次记录最小值的下标，与无序堆的第一个位置交换。
冒泡排序每次记录最后一次交换的下标，提高效率。
插入排序将数一个个加入temp数组，插入时保持有序。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX_COUNT 21000

int number1[MAX_COUNT];
int number2[MAX_COUNT];
int number3[MAX_COUNT];

bool fwrite(int number[],char* name)    //写入文件
{
    FILE *fp;
    if((fp=fopen(name,"w"))==NULL)
        return false;
    for(int i=0;i<MAX_COUNT;++i)
        fprintf(fp,"%d\n",number[i]);
    fclose(fp);
    return true;
}

void sort1()                            //选择排序法
{
    for(int i=0;i<MAX_COUNT-1;i++)
    {
        int minindex=i;                 //最小值下标
        for(int j=i;j<MAX_COUNT;++j)
            if(number1[minindex]>number1[j])
                minindex=j;
        int temp=number1[i];
        number1[i]=number1[minindex];
        number1[minindex]=temp;
    }
    if(fwrite(number1,"sort_1.txt"))
        printf("选择排序：写入成功！\n");
    else
        printf("选择排序：写入失败！\n");
}

void sort2()                            //冒泡排序
{
    int i=MAX_COUNT-1;
    while(i>0)
    {
        int index=0;                        //记录最后一次交换的下标
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
        printf("冒泡排序：写入成功！\n");
    else
        printf("冒泡排序：写入失败！\n");
}

void sort3()                               //插入排序
{
    int temp[MAX_COUNT];
    for(int i=0;i<MAX_COUNT;++i)
    {
        bool last=false;                    //是否放在末尾
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
        printf("插入排序：写入成功！\n");
    else
        printf("插入排序：写入失败！\n");
}

int main()
{
    srand((unsigned) time(NULL));       //用时间做种，每次产生随机数不一样
    for (int i=0; i<MAX_COUNT; i++)         //生成21000个数
    {
        number1[i] = number2[i] = number3[i] = rand();             //产生随机数
        printf("%d %d\n",i,number1[i]);
    }
    //sort1();        //选择排序
    //sort2();        //冒泡排序
    sort3();        //插入排序
    return 0;
}
