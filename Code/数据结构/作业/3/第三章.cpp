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
            else b1=false;         //只有右括号也为不成功
        }
        if(c=='[') b2=false;
        if(c==']')
        {
            if(!b2) b2=true;
            else b2=false;
        }
    }
    if(b1&&b2) printf("匹配成功！\n");
    else printf("匹配不成功！\n");
}

//3.30
typedef struct Cqueue{
    int n;
    Cqueue* next;
}Cqueue;
Cqueue* out(Cqueue* rear);

void q30(int length)
{
    //创建队列
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
    //判断是否队满
    int count=1;
    Cqueue *p=rear;
    do{
        p=p->next;
        ++count;
    }while(p->next!=rear);
    printf("队%s满\n",(count<length?"没有":""));
    //入队列
    p=(Cqueue*)malloc(sizeof(Cqueue));
    p->n=length;
    p->next=h;
    rear->next=p;
    rear=p;

    p=out(rear);
    printf("队头元素：%d\n",p->n);
}
//出队列
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
    printf("%s回文\n",b?"是":"不是");
}
int main()
{
    while(true)
    q31();
    return 0;
}
