#include <iostream>
#include <string>

using namespace std;

template<class T>
class Cpriority_queue{
private:
    struct Unit{
        T data;
        Unit* next;
    }*head;
    int length;
public:
    Cpriority_queue():head(NULL),length(0) {}
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
    Unit* p=head=NULL;
    Unit* t=pq.head;
    for(int i=0;i<length;++i)
    {
        if(i)
        {
            p->next=new Unit;
            p->next->data=t->data;
            p=p->next;
        }
        else{
            head=new Unit;
            head->data=t->data;
            head->next=NULL;
            p=head;
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
    (*this).~Cpriority_queue();
    length=pq.size();
    Unit* p=head=NULL;
    Unit* t=pq.head;
    for(int i=0;i<length;++i)
    {
        if(i)
        {
            p->next=new Unit;
            p->next->data=t->data;
            p=p->next;
        }
        else{
            head=new Unit;
            head->data=t->data;
            head->next=NULL;
            p=head;
        }
        t=t->next;
    }
}

template<class T>
void Cpriority_queue<T>::push(const T & t)
{
    ++length;
    Unit* p=new Unit;
    p->data=t;
    if(!head)
    {
        head=p;
        head->next=NULL;
        return;
    }
    if(t<head->data)
    {
        p->next=head;
        head=p;
        return;
    }
    Unit* temp=head;
    while(temp->next)
    {
        if(temp->next->data>=t)
        {
            p->next=temp->next;
            temp->next=p;
            return;
        }
        temp=temp->next;
    }
    temp->next=p;
    p->next=NULL;
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
    string type;
    while(cin >> type >> n)
    {
        if(type=="int")
            Prase<int>(n);
        if(type=="string")
            Prase<string>(n);
    }
    return 0;
}
