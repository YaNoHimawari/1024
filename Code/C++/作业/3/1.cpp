#include<iostream>
#define MAXSIZE 100

using namespace std;

class collection{
private:
    int c[MAXSIZE];
    int length;         //最大长度
    int n;              //当前长度
public:
    collection(int x): length(x),n(0){}
    int getlength()
    {
        return n;
    }
    void add(int x)
    {
        if(n<length)
        {
            bool b=true;
            for(int i=0;i<n;++i)
                if(c[i]==x)
                    b=false;
            if(b) c[n++]=x;
            csort();
        }
    }
    void  csort()     //排序
    {
        for(int i=0;i<n-1;++i)
            for(int j=0;j<n-1-i;++j)
                if(c[j]>c[j+1])
                {
                    int t=c[j];
                    c[j]=c[j+1];
                    c[j+1]=t;
                }
    }
    void del(int x)  //x为删除数字所在位数
    {
        if(x<=n && x>0)
        {
            if(x<n)
            for(int i=x-1;i<n-1;++i)
                c[i]=c[i+1];
            --n;
        }
    }
    int csearch(int x)  //x为数字位数
    {
        return c[x-1];
    }
    void show()
    {
        cout << '{';
        for(int i=0;i<n;++i)
        {
            if(i) cout << ',';
            cout << c[i];
        }
        cout << '}' << endl;
    }
    collection cunion(collection &a)        //并集
    {
        collection u(n+a.getlength());
        for(int i=0;i<n;++i)
            u.add(c[i]);
        for(int i=1;i<=a.getlength();++i)
            u.add(a.csearch(i));
        return u;
    }
    collection cintersection(collection &a)        //交集
    {
        collection t(n>a.getlength()?a.getlength():n);
        int d=1;
        for(int i=0;i<n;++i)
            for(int j=d;j<=a.getlength();++j)
                if(c[i]==a.csearch(j))
                {
                    t.add(c[i]);
                    d=j+1;
                    break;
                }
        t.csort();
        return t;
    }
    collection cdifference(collection &a)   //差集
    {
        collection d(*this);
        int t=1;
        for(int i=1;i<=d.getlength();++i)
            for(int j=t;j<=a.getlength();++j)
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
    collection c1(m);
    collection c2(n);
    for(int i=0;i<m;++i)
    {
        cin >> x;
        c1.add(x);
    }
    for(int i=0;i<n;++i)
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
