#include <iostream>

using namespace std;

class cstring
{
private:
    char* s;
    int length;
public:
    ~cstring();
    cstring(): s(NULL),length(0) {}
    cstring(const char c);
    cstring(const char* cs);
    cstring(const cstring & cs);                //复制构造
    int slength() const;                        //字符串长度
    char sat(int n) const;                      //获取第i位的字符
    cstring & operator = (const cstring & cs);  //赋值
    friend istream & operator >> (istream & is,cstring & cs);     //输入
    friend ostream & operator << (ostream & os,const cstring & cs);     //输出
    cstring operator + (const cstring & cs) const;  //连接并返回结果
    void sappend(const cstring & cs);           //连接并将结果赋值给自身
    cstring ssubstr(int pos,int n) const;       //取子串
};

cstring::~cstring()
{
    length=0;
    delete[]  s;
    s=NULL;
}

cstring::cstring(const char c)
{
    s=new char[1];
    s[0]=c;
    length=1;
}

cstring::cstring(const char* cs)
{
    length=0;
    while(cs[length]!='\0')
        ++length;
    s=new char[length+1];           //末位加上'\0'
    for(int i=0; i<=length; ++i)
        s[i]=cs[i];
}

cstring::cstring(const cstring & cs)
{
    this->length=cs.slength();
    s=new char[length+1];
    for(int i=0; i<=length; ++i)
        s[i]=cs.sat(i);
}

int cstring::slength() const
{
    return length;
}

char cstring::sat(int n) const
{
    return s[n];
}

cstring & cstring::operator = (const cstring & cs)
{
    (*this).~cstring();
    length=cs.slength();
    s=new char[length+1];
    for(int i=0; i<=length; ++i)
        s[i]=cs.sat(i);
    return *this;
}

istream & operator >> (istream & is,cstring & cs)
{
    char c;
    int i=0;
    char* s=new char[200];
    while((c=is.get())!='\n')
        s[i++]=c;
    s[i]='\0';
    cs=s;
    delete[] s;
    return is;
}

ostream & operator << (ostream & os,const cstring & cs)
{
    for(int i=0; i<cs.slength(); ++i)
        os << cs.sat(i);
    return os;
}

cstring cstring::operator+(const cstring & cs) const
{
    char* t=new char[length+cs.slength()+1];
    int i;
    for(i=0; i<length; ++i)
        t[i]=s[i];
    for(int j=0; j<=cs.slength(); ++j)
        t[i++]=cs.sat(j);
    cstring temp(t);
    delete[] t;
    return temp;
}

void cstring::sappend(const cstring & cs)
{
    *this=*this+cs;
}

cstring cstring::ssubstr(int pos,int n) const
{
    char* t=new char[n+1];
    int i;
    for(i=0; i<n; ++i)
    {
        if(pos+i>=length)   break;
        t[i]=s[pos+i];
    }
    t[i]='\0';
    cstring temp(t);
    delete[] t;
    return temp;
}

int main()
{
    cstring S[100];
    cin >> S[1] >> S[2];

    char c;
    while(cin >> c)
    {
        if(c=='P')
        {
            int i;
            cin >> i;
            cout << S[i] << endl;
        }
        if(c=='A')
        {
            int i,j;
            cin >> i >> j;
            S[j]=S[i];
        }
        if(c=='C')
        {
            int i,j,k;
            cin >> i >> j >> k;
            S[k]=S[i]+S[j];
        }
        if(c=='F')
        {
            int i,s,l,k;
            cin >> i >> s >> l >> k;
            S[k]=S[i].ssubstr(s,l);
        }
    }
    return 0;
}
