#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

bool a(int n)
{
    for(int i=2;i<n;++i)
        if(n%i==0) return false;
    return true;
}

int main()
{
    vector<int> V;
    queue<int> Q;
    stack<int> S1,S2;
    int n;

    cin >> n;
    while(n)
    {
        if(n<0)
            V.push_back(n);
        if(n>0)
       {
            if(a(n)) Q.push(n);
            if(n%2==0) S1.push(n);
            else S2.push(n);
       }
        cin >> n;
    }

    for(int i=0;i<(int)V.size();++i)
        cout << V[i] << "\t";
    cout <<endl;

    while(!Q.empty())
    {
        cout << Q.front() << "\t";
        Q.pop();
    }
    cout << endl;

    while(!S1.empty())
    {
        cout << S1.top() <<"\t";
        S1.pop();
    }
    cout << endl;

    while(!S2.empty())
    {
        cout << S2.top() <<"\t";
        S2.pop();
    }
    cout << endl;

    return 0;

}
