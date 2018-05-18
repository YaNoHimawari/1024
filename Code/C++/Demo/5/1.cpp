#include <iostream>
#include <string>

using namespace std;

struct longint
{
    int n;
    longint* prior;
    longint* next;
};

class Longint
{
private:
    longint *head,*last;
public:
    Longint(string s="")
    {
        head=NULL;
        last=NULL;
        trim(s);
        for(int i=0; i<s.length(); ++i)
        {
            char c=s.at(i);
            if(head==NULL && c=='0' && s.length()!=1)   continue;
            longint* t=new longint;
            t->n=c-48;
            t->prior=last;
            t->next=NULL;
            if(last)
                last->next=t;
            else
                head=t;
            last=t;
        }
    }
    ~Longint();
    bool setlint(string s);
    longint* getlast() const;
    longint* gethead() const;
    Longint operator + (const Longint & rL);
    Longint operator - (const Longint & rL);
    Longint(const Longint & rL);
    Longint & operator = (const Longint & rl);
    void display() const;
    string & trim(string & s);                  //去除首尾空格
};

Longint::~Longint()
{
    if(head)
    {
        longint* p=head->next;
        delete head;
        head=p;
    }
    last=NULL;
}

bool Longint::setlint(string s)
{
    (*this).~Longint();
    trim(s);
    for(int i=0; i<s.length(); ++i)
    {
        char c=s.at(i);
        if(head==NULL && c=='0' && s.length()!=1)   continue;
        longint* t=new longint;
        t->n=c-48;
        t->prior=last;
        t->next=NULL;
        if(last)
            last->next=t;
        else
            head=t;
        last=t;
    }

    return last;           //last为空则读取失败
}

longint* Longint::getlast() const
{
    return last;
}

longint* Longint::gethead() const
{
    return head;
}

Longint Longint::operator + (const Longint &rL)
{
    Longint temp1;
    string s="";
    longint* rl=rL.getlast();
    longint* p=last;
    bool b=false;                //进位的标志
    while(p!=NULL || rl!=NULL)
    {
        int sum=0;
        if(b)                       //进位处理
        {
            sum=1;
            b=false;
        }
        if(p&&!rl)
        {
            sum+=p->n;
            p=p->prior;
        }
        else if(!p&&rl)
        {
            sum+=rl->n;
            rl=rl->prior;
        }
        else
        {
            sum+= p->n + rl->n;
            p=p->prior;
            rl=rl->prior;
        }
        if(sum>=10)                //判断是否进位
        {
            sum-=10;
            b=true;
        }
        s+=(char)(sum+48);
    }
    if(b) s+="1";                   //首位如果进位加回10

    string result="";               //逆置
    for(int i=s.length()-1; i>=0; --i)
        result+=s.at(i);

    temp1.setlint(result);
    return temp1;
}

Longint Longint::operator-(const Longint & rL)
{
    Longint temp2;
    string s="";
    bool b=false;
    longint* rl=rL.getlast();
    longint* p=last;
    while(p)
    {
        int cha=0;
        if(b)
        {
            cha=-1;
            b=false;
        }
        if(rl==NULL)
        {
            cha+=p->n;
            p=p->prior;
        }
        else
        {
            cha+=p->n - rl->n;
            p=p->prior;
            rl=rl->prior;
        }
        if(cha<0)
        {
            cha+=10;
            b=true;
        }
        s+=(char)(cha+48);
    }

    string result="";                   //逆置
    for(int i=s.length()-1; i>=0; --i)
    {
        if(result!="" || s.at(i)!='0')  //除去多余的0
            result+=s.at(i);
    }
    if(result=="") result="0";

    temp2.setlint(result);
    return temp2;
}

Longint::Longint(const Longint & rL)
{
    head=last=NULL;
    longint* rh=rL.gethead();
    while(rh)
    {
        longint* t=new longint;
        t->n=rh->n;
        t->prior=last;
        t->next=NULL;
        if(last)
            last->next=t;
        else
            head=t;
        last=t;
        rh=rh->next;
    }
 }

Longint & Longint::operator=(const Longint & rL)
{
    (*this).~Longint();
    longint* rh=rL.gethead();
    while(rh)
    {
        longint* t=new longint;
        t->n=rh->n;
        t->prior=last;
        t->next=NULL;
        if(last)
            last->next=t;
        else
            head=t;
        last=t;
        rh=rh->next;
    }
    return *this;
}

void Longint::display() const
{
    longint* p=head;
    while(p)
    {
        cout << p->n;
        p=p->next;
    }
    cout << endl;
}

string & Longint::trim(string &s)
{
    if (s.empty())
        return s;

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}


int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        Longint t1;
        t1.setlint(s1);
        Longint t2(s2);

        Longint t3=t1+t2;
        t3.display();
        t3=t1-t2;
        t3.display();
    }

    return 0;
}
