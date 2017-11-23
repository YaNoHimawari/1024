#include <iostream>
#define MAXSIZE 100

using namespace std;

class stack
{
private:
    int top;
    int data[MAXSIZE];
public:
    stack()
    {
        top=0;
    }

    void push(int n)
    {
        if(top+1<MAXSIZE)
            data[++top]=n;
    }

    void pop()
    {
        if(!isempty())
            top--;
    }

    int top()
    {
        if(!isempty())
            return data[top];
        return 0;
    }

    bool isempty()
    {
        return top==0;
    }

};
/*class stack {
private:
   int data[N];
   int sp;
public:
   stack(){sp=N;};

   void push(int i) {
     if (sp>0) data[--sp] = i;
   }

   int top() {
     if (!isempty()) {
        return data[sp];
     }
     return 0;
   }

   void pop(){
    if (!isempty()) {
        sp++;
    }
   }

    bool isempty() {
        return sp==N;
    }
};*/

int main()
{
    int v,x;
    stack s1;
    stack s2;
    while(cin >> v >> x)
    {
        if(v==1)
            s1.push(x);
        if(v==2)
            s2.push(x);
    }
    while(!s1.isempty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    while(!s2.isempty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}
