/*
1.ʹ�����鱣��ÿһ������������������
2.ʹ��������ÿһ������������������
3.����n�ݼ���������s��������n<2ʱ�����s
4.s��������������������s
*/
#include <iostream>
#include <cstdlib>

using namespace std;

void q1(int n);
void q2(int n);
void q3(int n,int s);
void q4(int n);

int main()
{
    int n,r=1;;
    cin >> n;
    q1(n); q2(n); q3(n,r); q4(n);
    return 0;
}


void q1(int n)          //����ṹ
{
    int s[100];
    s[1]=1;
    for(int i=2;i<=n;++i)
        s[i]=(s[i-1]+1)*2;
    cout << s[n] <<endl;
}


typedef struct S
{
    int m;
    S* next;
}S;

void q2(int n)          //����ṹ
{
    S* L=(S*)malloc(sizeof(S));
    S* p=L;
    p->m=1;  p->next=NULL;
    for(int i=1;i<n;++i)
    {
        p->next=(S*)malloc(sizeof(S));
        p->next->m=(p->m+1)*2;
        p=p->next;
        p->next=NULL;
    }
    cout << p->m <<endl;
    p=L;
    while(p->next)
    {
        L=p->next;
        free(p);
        p=L;
    }
    free(p);
}


void q3(int n,int s)        //�ݹ鷽��
{
    if(n<2) cout << s <<endl;
    else q3(--n,(s+1)*2);
}


void q4(int n)              //����
{
    int a=1;
    for(int i=1;i<10;++i)
        a=(a+1)*2;
    cout << a <<endl;
}



