#include <iostream>
#include <string>

using namespace std;

template<class T>
struct Unit
{
    Unit * next;
    T data;
};

template<class T>
class cirB
{
private:
    Unit<T> *head;
    Unit<T> *tail;
    int length;
    int max_length;
 public:
     class myIterator
    {
        private:
        Unit<T> * init;
        public:
        myIterator():init(NULL){}
        myIterator(Unit<T> * init)
        {
            this->init=init;
        }
        myIterator(const myIterator & it)
        {
            init=it.init;
        }
        bool operator !=(const myIterator & it)
        {
            return this->init!=it.init;
        }
        void operator ++()
        {
            this->init=init->next;
        }
        void operator ++(int)
        {
            this->init=init->next;
        }
        Unit<T> operator *()
        {
            return *init;
        }
    };
public:
    cirB(int n);
    cirB(const cirB & cb);
    ~cirB();
    int size() const {return length;}
    bool empty() const {return length==0;}
    bool full() const {return length==max_length;}
    int capacity() const {return max_length;}
    cirB & operator = (const cirB & cb);
    void push_back(const T & t);
    void pop_front();
    myIterator begin() const {return myIterator(head);}
    myIterator end() const {return myIterator(tail);}
    void Parse ();
};

template<class T>
cirB<T>::cirB(int n)
{
    length=0;
    max_length=n;
    head=tail=NULL;
}

template<class T>
cirB<T>::cirB(const cirB & cb)
{
    head=tail=NULL;
    length=cb.size();
    max_length=cb.capacity();
    bool b=true;
    myIterator it;
    for(it=cb.begin();it!=cb.end();++it)
    {
        if(b)
        {
            head=new Unit<T>;
            tail=head;
            tail->data=it->data;
            b=false;
        }
        else
        {
            tail->next=new Unit<T>;
            tail->next->data=it->data;
            tail=tail->next;
        }
    }
    tail->next=head;
}

template<class T>
cirB<T>::~cirB()
{
    Unit<T> *p;
    for(int i=0;i<length;++i)
    {
        p=head;
        head=head->next;
        delete p;
    }
}

template<class T>
cirB<T> & cirB<T>::operator = (const cirB & cb)
{
    if(this==&cb) return *this;
    (*this).~cirB();
    head=tail=NULL;
    length=cb.size();
    max_length=cb.capacity();
    bool b=true;
    myIterator it;
    for(it=cb.begin();it!=cb.end();++it)
    {
        if(b)
        {
            head=new Unit<T>;
            tail=head;
            tail->data=it->data;
            b=false;
        }
        else
        {
            tail->next=new Unit<T>;
            tail->next->data=it->data;
            tail=tail->next;
        }
    }
    tail->next=head;
}

template<class T>
void cirB<T>::push_back(const T & t)
{
    if(!full())
    {
        Unit<T> *p=new Unit<T>;
        p->data=t;
        ++length;
        if(tail)
        {
            tail->next=p;
            tail=p;
            tail->next=head;
        }
        else
        {
            head=tail=p;
            tail->next=head;
        }
    }
    else
    {
        tail=head;
        tail->data=t;
        head=head->next;
    }
}

template<class T>
void cirB<T>::pop_front()
{
    if(length==0)   return;
    T t=(*head).data;
    cout << t << " ";
    if(length==1)
    {
        delete head;
        head=tail=NULL;
    }
    else
    {
        Unit<T> *p=head;
        head=head->next;
        tail->next=head;
        delete p;
    }
    --length;
}

template	<class T>
void cirB<T>::Parse ()
{
	string	cmd;
	T		x;
	int		index;
	while (cin >> cmd)
    {
        if (cmd == "quit")
            break;
        else if (cmd == "push")
        {
            cin >> x;
            push_back (x);
        }
        else if (cmd == "pop")
        {
            pop_front();
        }
        else if (cmd=="print")
        {
            bool b=true;
            myIterator it;
            for(it=begin();b||it!=begin();++it)
            {
                T t=(*it).data;
                cout << t << " ";
                b=false;
            }
        }
	}
	cout << endl;
}


int main()
{
    int n;
    string type;
    while(cin >> type >> n)
    {
        if(type=="int")
        {
            cirB<int> cb(n);
            cb.Parse();
        }
        if(type=="string")
        {
            cirB<string> cb(n);
            cb.Parse();
        }
    }
    return 0;
}
