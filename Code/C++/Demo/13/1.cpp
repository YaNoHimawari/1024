#include <iostream>
#include <string>

using namespace std;

template<class T>
class Cpriority_queue{
private:
    struct Unit{
        T data;
        Unit* next;
    }*head,*tail;
    int length;
public:
    Cpriority_queue():head(NULL),tail(NULL),length(0) {}
    Cpriority_queue(const Cpriority_queue & pq);
    ~Cpriority_queue();
    int size() const {return length;}
    bool empty() const {return length==0;}
    Cpriority_queue & operator = (const Cpriority_queue & pq);
    void push(const T & t);
    void pop();
    void display();
};

template<class T>
Cpriority_queue<T>::Cpriority_queue(const Cpriority_queue<T> & pq)
{
    length=pq.size();
    head=tail=NULL;
    Unit* t=pq.head;
    for(int i=0;i<length;++i)
    {
        if(i)
        {
            tail->next=new Unit;
            tail->next->data=t->data;
            tail=tail->next;
        }
        else{
            head=new Unit;
            head->data=t->data;
            head->next=NULL;
            tail=head;
        }
        t=t->next;
    }
}

template<class T>
Cpriority_queue<T>::~Cpriority_queue()
{
    while(head)
    {
        Unit *t=head;
        head=head->next;
        delete t;
    }
}

template<class T>
Cpriority_queue<T> & Cpriority_queue<T>::operator = (const Cpriority_queue<T> & pq)
{
    if(this==&pq) return *this;
    (*this).~Cpriority_queue();
    length=pq.size();
    head=tail=NULL;
    Unit* t=pq.head;
    for(int i=0;i<length;++i)
    {
        if(i)
        {
            tail->next=new Unit;
            tail->next->data=t->data;
            tail=tail->next;
        }
        else{
            head=new Unit;
            head->data=t->data;
            head->next=NULL;
            tail=head;
        }
        t=t->next;
    }
    return *this;
}

template<class T>
void Cpriority_queue<T>::push(const T & t)
{
    ++length;
    Unit* p=new Unit;
    p->data=t;
    p->next=NULL;
    if(!head)
        head=tail=p;
   else
   {
       tail->next=p;
       tail=p;
   }
}

template<class T>
void Cpriority_queue<T>::pop()
{
    if(empty()) return;
    T t=head->data;
    Unit* p=head;
    head=head->next;
    delete p;
    --length;
    cout << t << " ";
}

template<class T>
void Cpriority_queue<T>::display()
{
    while(!empty())
       pop();
}

template<class T>
void Prase(int n)
{
    Cpriority_queue<T> q[2];
    char c;
    for(int i=0;i<n;++i)
    {
        int x;
        cin >> c >> x;
        if(c=='E')
        {
            T t;
            cin >> t;
            q[x-1].push(t);
        }
        else if(c=='D')
            q[x-1].pop();
        else if(c=='A')
            q[x-1].display();
    }
}

int main()
{
    int n;
    cin >> n;
    Prase<int>(n);
    return 0;
}
