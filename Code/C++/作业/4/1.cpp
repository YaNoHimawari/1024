#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct number
{
    int n;
    number* next;
} number;

class collection
{
private:
    number* h;
    int length;
public:
    //构造函数
    collection(): length(0)
    {
        h=(number*)malloc(sizeof(number));
        h->n=0;
        h->next=NULL;
    }
    //深度复制
    collection(const collection &a)
    {
        h=(number*)malloc(sizeof(number));
        h->n=0;
        h->next=NULL;
        number* p=h;
        for(int i=1; i<=a.getlength(); ++i)
        {
            p->next=(number*)malloc(sizeof(number));
            p->next->n=a.csearch(i);
            p->next->next=NULL;
            p=p->next;
        }
        length=a.getlength();
    }
    //运算符重载
    collection operator = (const collection &a)
    {
        (*this).~collection();
        h=(number*)malloc(sizeof(number));
        h->n=0;
        h->next=NULL;

        number* p=h;
        for(int i=1; i<a.getlength(); ++i)
        {
            p->next=(number*)malloc(sizeof(number));
            p->next->n=a.csearch(i);
            p->next->next=NULL;
            p=p->next;
        }
        return *this;
    }
    //析构函数
    ~collection()
    {
        while(h)
        {
            number *p=h;
            h=h->next;
            free(p);
        }
    }
    int getlength() const
    {
        return length;
    }
    void add(int x)
    {
        number* p=h;
        bool b=true;
        while(p->next!=NULL)
        {
            if(p->next->n==x)
            {
                b=false;
                break;
            }
            else if(p->next->n > x) break;
            p=p->next;
        }
        if(b)
        {
            number* t=p->next;
            p->next=(number*)malloc(sizeof(number));
            p->next->n=x;
            p->next->next=t;
            ++length;
        }
    }
    void del(int x)  //x为删除数字所在位数
    {
        if(x<=length && x>0)
        {
            number *p=h;
            for(int i=1; i<x; ++i)
            {
                p=p->next;
            }
            number* t=p->next;
            p->next=t->next;
            free(t);
            --length;
        }
    }
    int csearch(int x) const //x为数字位数
    {
        if(x<=length)
        {
            number* p=h;
            for(int i=0; i<x; ++i)
                p=p->next;
            return p->n;
        }
        else return 0;
    }
    void show() const
    {
        number* p=h->next;
        cout << '{';
        for(int i=0; i<length; ++i)
        {
            if(i) cout << ',';
            cout << p->n;
            p=p->next;
        }
        cout << '}' << endl;
    }
    collection cunion(const collection &a)        //并集
    {
        collection u;
        number* p=h->next;
        while(p)
        {
            u.add(p->n);
            p=p->next;
        }

        for(int i=1; i<=a.getlength(); ++i)
            u.add(a.csearch(i));
        return u;
    }
    collection cintersection(const collection &a)        //交集
    {
        collection t;
        int d=1;
        for(int i=1; i<=length; ++i)
            for(int j=d; j<=a.getlength(); ++j)
                if(csearch(i)==a.csearch(j))
                {
                    t.add(csearch(i));
                    d=j+1;
                    break;
                }
        return t;
    }
    collection cdifference(const collection &a)   //差集
    {
        collection d(*this);
        int t=1;
        for(int i=1; i<=d.getlength(); ++i)
            for(int j=t; j<=a.getlength(); ++j)
                if(d.csearch(i)==a.csearch(j))
                {
                    d.del(i);
                    --i;
                    t=j+1;
                    break;
                }
        return d;
    }
};


int main()
{
    int m,n,x;
    cin >> m >> n;
    collection c1;
    collection c2;
    for(int i=0; i<m; ++i)
    {
        cin >> x;
        c1.add(x);
    }
    for(int i=0; i<n; ++i)
    {
        cin >> x;
        c2.add(x);
    }
    c1.show();
    c2.show();
    c1.cunion(c2).show();
    c1.cintersection(c2).show();
    c1.cdifference(c2).show();
    return 0;
}
