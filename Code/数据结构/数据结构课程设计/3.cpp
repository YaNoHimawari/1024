/*
ʹ��˫�������泤������
���ʱʹ��βָ����ǰ�ƶ���ӡ��ݹ���ӣ�b��ʾ�Ƿ��λ�������б��������һλ���������
�ͷ������ڴ档
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct longint{         //˫������
    int n;                      //һ����㴢��һλ��
    longint* prior;
    longint* next;
}longint;

void get();
void sum(longint* l1,longint* l2,bool b);
void d_free(longint* l);

void get()                      //��ȡ����������������
{
    char c;
    longint* p=NULL;

    while((c=getchar())!='\n')      //�س���ʾ�������
    {
        longint* t=(longint*)malloc(sizeof(longint));
        t->n=c-48;                  //�ַ�-48Ϊ��Ӧ����
        t->prior=p; t->next=NULL;
        if(p)
            p->next=t;
         p=t;
    }
    longint* l1=p;                  //��һ��������

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
    longint* l2=p;                  //�ڶ���������

    sum(l1,l2,false);
    cout << endl;

    d_free(l1);
    d_free(l2);
}

void sum(longint* l1,longint* l2,bool b)    //��Ӻ������ݹ鷽ʽ��b��ʾ�Ƿ��λ���߼ӱ����
{
    int s=b?1:0;                //sΪ��ǰλ��ӵĽ��
    b=false;
    if(!l1&&!l2)                //��һλ
    {
        if(s) cout << s;
        return;
    }
    else if(l1&&!l2)            //�ڶ���������������
    {
        s+=l1->n;
        if(s>=10)
        {
            s-=10; b=true;
        }
        sum(l1->prior,NULL,b);
    }
    else if(!l1&&l2)            //��һ��������������
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
    cout << s;                  //�����ǰλ���
}

void d_free(longint* l)         //�ͷ��ڴ�
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
