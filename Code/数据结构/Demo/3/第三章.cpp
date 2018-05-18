#include<stdio.h>
#include<stdlib.h>

//3.18
void q18()
{
    char c;
    bool b1=true,b2=true;
    while((c=getchar())!='\n')
    {
        if(c=='(') b1=false;
        if(c==')')
        {
            if(!b1) b1=true;
            else b1=false;         //ֻ��������ҲΪ���ɹ�
        }
        if(c=='[') b2=false;
        if(c==']')
        {
            if(!b2) b2=true;
            else b2=false;
        }
    }
    if(b1&&b2) printf("ƥ��ɹ���\n");
    else printf("ƥ�䲻�ɹ���\n");
}

//3.30
typedef struct Cqueue{
    int n;
    Cqueue* next;
}Cqueue;
Cqueue* out(Cqueue* rear);

void q30(int length)
{
    //��������
    Cqueue *h=NULL,*rear=NULL;
    for(int i=1;i<length;++i)
    {
        Cqueue* t=(Cqueue*)malloc(sizeof(Cqueue));
        t->n=i;
        t->next=NULL;
        if(!rear) h=rear=t;
        else{rear->next=t; rear=t;}
    }
    rear->next=h;
    //�ж��Ƿ����
    int count=1;
    Cqueue *p=rear;
    do{
        p=p->next;
        ++count;
    }while(p->next!=rear);
    printf("��%s��\n",(count<length?"û��":""));
    //�����
    p=(Cqueue*)malloc(sizeof(Cqueue));
    p->n=length;
    p->next=h;
    rear->next=p;
    rear=p;

    p=out(rear);
    printf("��ͷԪ�أ�%d\n",p->n);
}
//������
Cqueue* out(Cqueue* rear)
{
    Cqueue* p=rear->next;
    rear->next=p->next;
    free(p); p=NULL;
    return rear->next;
}

//3.31
void q31()
{
    char s[100];
    int length=0;
    scanf("%s",s);
    while(s[length]!='@')
        ++length;
    int n=length/2;
    bool b=true;
    for(int i=0;i<n;++i)
    {
        if(s[i]!=s[length-i-1])
        {
            b=false; break;
        }
    }
    printf("%s����\n",b?"��":"����");
}
int main()
{
    while(true)
    q31();
    return 0;
}
