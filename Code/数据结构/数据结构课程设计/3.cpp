/*
使用双向链表保存长整数。
相加时使用尾指针向前移动相加。递归相加，b表示是否进位，边运行边输出，第一位最先输出。
释放链表内存。
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct longint{         //双向链表
    int n;                      //一个结点储存一位数
    longint* prior;
    longint* next;
}longint;

void get();
void sum(longint* l1,longint* l2,bool b);
void d_free(longint* l);

void get()                      //读取长整数并构建链表
{
    char c;
    longint* p=NULL;

    while((c=getchar())!='\n')      //回车表示输入结束
    {
        longint* t=(longint*)malloc(sizeof(longint));
        t->n=c-48;                  //字符-48为对应数字
        t->prior=p; t->next=NULL;
        if(p)
            p->next=t;
         p=t;
    }
    longint* l1=p;                  //第一个长整数

    p=NULL;
    while((c=getchar())!='\n')
    {
        longint* t=(longint*)malloc(sizeof(longint));
        t->n=c-48;
        t->prior=p; t->next=NULL;
        if(p)
            p->next=t;
         p=t;
    }
    longint* l2=p;                  //第二个长整数

    sum(l1,l2,false);
    cout << endl;

    d_free(l1);
    d_free(l2);
}

void sum(longint* l1,longint* l2,bool b)    //相加函数，递归方式，b表示是否进位，边加边输出
{
    int s=b?1:0;                //s为当前位相加的结果
    b=false;
    if(!l1&&!l2)                //第一位
    {
        if(s) cout << s;
        return;
    }
    else if(l1&&!l2)            //第二个长整数相加完毕
    {
        s+=l1->n;
        if(s>=10)
        {
            s-=10; b=true;
        }
        sum(l1->prior,NULL,b);
    }
    else if(!l1&&l2)            //第一个长整数相加完毕
    {
        s+=l2->n;
        if(s>=10)
        {
            s-=10; b=true;
        }
        sum(NULL,l2->prior,b);
    }
    else
    {
        s+= l1->n + l2->n;
        if(s>=10)
        {
            s-=10; b=true;
        }
        sum(l1->prior,l2->prior,b);
    }
    cout << s;                  //输出当前位结果
}

void d_free(longint* l)         //释放内存
{
    longint* p=l;
    while(p->prior)
    {
        l=p->prior;
        free(p);
        p=l;
    }
    free(p); p=NULL;
    l=NULL;
}

int main()
{
    get();
    return 0;
}
