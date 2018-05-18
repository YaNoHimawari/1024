#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//4.10
void q10(string s)
{
    string rs;
    for(int i=s.length()-1;i>=0;--i)
        rs+=s.at(i);
    s=rs;
    cout << s << endl;
}

//4.11
void q11(string s,string t)
{
    string r;
    int n=0;
    int* index=(int*)calloc(s.length(),sizeof(int)); //储存位置
    for(int i=0;i<s.length();++i)
    {
        if(r.find(s.at(i))!=(-1))       //判断是否重复
            continue;
        bool b=true;
        for(int j=0;j<t.length();++j)
            if(s.at(i)==t.at(j))
            {
                b=false; break;
            }
        if(b)
        {
            r+=s.at(i);
            index[n++]=i+1;
        }
    }
    cout << r <<endl;
    for(int i=0;i<r.length();++i)
        cout << r.at(i) << " " << index[i] << endl;
    free(index);
}

//4.13
int* Next(string t)
{
    if(t.length()<1) return NULL;
    int* next=(int*)calloc(t.length()+1,sizeof(int));
    int j=1,k=0;
    next[1]=0;
    while(j<t.length())
    {
        if(k==0 || t.at(j-1)==t.at(k-1))
        {
            ++j; ++k; next[j]=k;
        }
        else k=next[k];
    }
    return next;
}

int KMP(string s,string t)              //返回匹配时所在位置
{
    int i=1,j=1;
    int* next=Next(t);
    while(i<=s.length() && j<=t.length())
    {
        if(j==0 || s.at(i-1)==t.at(j-1))
        {
            ++i; ++j;
        }
        else j=next[j];
    }
    free(next);
    if(j>t.length()) return i-j;
    else return -1;
}

void q13(string s,string t)
{
    if(s.length()<t.length())
    {
        cout << s << endl; return;
    }
    int n;
    while((n=KMP(s,t))!=-1)
        s.erase(n,t.length());
    cout << s << endl;
}

int main()
{
     string s1,s2;
     cin >> s1 >> s2;
//    q10(s);
//    q11(s1,s2);
//    q13(s1,s2);
    return 0;
}
