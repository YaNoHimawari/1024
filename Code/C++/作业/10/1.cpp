#include <iostream>
#include <string>

using namespace std;

template <class T>
class cvector
{
private:
    T* head;
    int length;
public:
    cvector():head(NULL),length(0) {}
    cvector(int n);                         //n为初始长度
    cvector(const cvector<T> & v);             //拷贝构造
    ~cvector();                             //析构函数
    void push(const T & t);
    void put(int index,const T & t);
    void fetch(int index) const;
    void check(int index) const;
    cvector & operator = (const cvector<T> & v);//赋值
    T & operator [] (int index) const;      //读取
    int vsize() const;                      //长度
};

template <class T>
cvector<T>::cvector(int n)
{
    head=new T[n];
    length=n;
}

template <class T>
cvector<T>::cvector(const cvector<T> & v)
{
    length=v.vsize();
    head=new T[length];
    for(int i=0; i<length; ++i)
        head[i]=v[i];
}

template <class T>
cvector<T>::~cvector()
{
    delete [] head;
}

template <class T>
void cvector<T>::push(const T & t)
{
    T* h=new T[length+1];
    for(int i=0;i<length;++i)
        h[i]=head[i];
    h[length]=t;
    ++length;
    T* temp=h;
    h=head;
    head=temp;
    delete [] h;
}

template<class T>
void cvector<T>::put(int index,const T & t)
{
    try
    {
        check(index);
        head[index]=t;
    }
    catch(int n)
    {
        cout << "invalid index:" << n << " ";
    }
}

template <class T>
void cvector<T>::fetch(int index) const
{
    try
    {
        check(index);
        cout << head[index] << " ";
    }
    catch(int n)
    {
        cout << "invalid index:" << n << " ";
    }
}

template <class T>
void cvector<T>::check(int index) const
{
    if(index<0||index>=length)
        throw index;
}

template <class T>
cvector<T> & cvector<T>::operator = (const cvector<T> & v)
{
    if(this==&v) return *this;
    (*this).~cvector();
    length=v.vsize();
    head=new T[length];
    for(int i=0; i<length; ++i)
        head[i]=v[i];
    return *this;
}

template <class T>
T & cvector<T>::operator [] (int index) const
{
    return head[index];
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
    int n;
    string s;
    while(cin >> s >> n)
    {
        if(s=="int")
        {
            string t;
            cvector<int> vint(n);
            while(cin >> t)
            {
                if(t=="quit")
                    break;
                if(t=="push")
                {
                    int data;
                    cin >> data;
                    vint.push(data);
                }
                if(t=="put")
                {
                    int index,data;
                    cin >> index >> data;
                    vint.put(index,data);
                }
                if(t=="fetch")
                {
                    int index;
                    cin >> index;
                    vint.fetch(index);
                }
            }
        }
        if(s=="string")
        {
            string t;
            cvector<string> vstring(n);
            while(cin >> t)
            {
                if(t=="quit")
                    break;
                if(t=="push")
                {
                    string data;
                    cin >> data;
                    vstring.push(data);
                }
                if(t=="put")
                {
                    int index;
                    string data;
                    cin >> index >> data;
                    vstring.put(index,data);
                }
                if(t=="fetch")
                {
                    int index;
                    cin >> index;
                    vstring.fetch(index);
                }
            }
        }
    }
    return 0;
}
