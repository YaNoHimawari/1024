#include <iostream>

using namespace std;

template <class T>
class cvector
{
private:
    struct vec
    {
        T data;
        vec* next;
    }*head;
    int length;
public:
    cvector():head(NULL),length(0) {}
    cvector(int n);                         //n为初始长度
    cvector(const cvector<T> & v);             //拷贝构造
    ~cvector();                             //析构函数
    void add(const T & t);                   //添加
    cvector & operator = (const cvector<T> & v);//赋值
    T & operator [] (int index) const;      //读取
    int vsize() const;                      //长度
};

template <class T>
cvector<T>::cvector(int n)
{
    head=NULL;
    vec* p=NULL;
    for(length=0; length<n; ++length)
    {
        if(!head)
        {
            head=new vec;
            head->next=NULL;
            p=head;
            continue;
        }
        p->next=new vec;
        p->next->next=NULL;
        p=p->next;
    }
}

template <class T>
cvector<T>::cvector(const cvector<T> & v)
{
    head=NULL;
    vec* p=NULL;
    for(length=0; length<v.vsize(); ++length)
    {
        if(!head)
        {
            head=new vec;
            head->data=v[length];
            head->next=NULL;
            p=head;
            continue;
        }
        p->next=new vec;
        p->next->data=v[length];
        p->next->next=NULL;
        p=p->next;
    }
}

template <class T>
cvector<T>::~cvector()
{
    while(head)
    {
        vec* p=head;
        head=head->next;
        delete p;
    }
}

template <class T>
void cvector<T>::add(const T & t)
{
    vec* p=head;
    while(p->next)
        p=p->next;
    p->next=new vec;
    p->next->data=t;
    p->next->next=NULL;
    ++length;
}

template <class T>
cvector<T> & cvector<T>::operator = (const cvector<T> & v)
{
    if(this==&v) return *this;
    (*this).~cvector();
    head=NULL;
    vec* p=NULL;
    for(length=0; length<v.vsize(); ++length)
    {
        if(!head)
        {
            head=new vec;
            head->data=v[length];
            head->next=NULL;
            p=head;
            continue;
        }
        p->next=new vec;
        p->next->data=v[length];
        p->next->next=NULL;
        p=p->next;
    }
    return *this;
}

template <class T>
T & cvector<T>::operator [] (int index) const
{
    vec* p=head;
    for(int i=0; i<index; ++i)
        p=p->next;
    return p->data;
}


template <class T>
int cvector<T>::vsize() const
{
    return length;
}

template <class T>
void display(const cvector<T> & v)
{
    for(int i=0; i<v.vsize(); ++i)
    {
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int m,n;
    cin >> m >> n;
    cvector<int> v1(m);
    for(int i=0; i<m; ++i)
        v1[i]=i+1;
    cvector<int> v2(n);
    for(int i=0; i<n; ++i)
        v2[i]=2*i;
    cvector<int> v3=v2;

    int v,x;
    while(cin >> v >> x)
        switch(v)
        {
        case 1:
            v1.add(x);
            break;
        case 2:
            v2.add(x);
            break;
        case 3:
            v3.add(x);
            break;
        }

    display(v1);
    display(v2);
    display(v3);
    return 0;
}
