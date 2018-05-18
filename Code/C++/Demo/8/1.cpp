#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class matrix{
private:
    struct point{
        int x,y;
    };
    int row,col;
    vector< vector<int> > v;
public:
    matrix():row(0),col(0){}
    matrix(int m,int n):row(m),col(n){}
    bool m_set();               //设置矩阵
    int connect();              //求连通块数,递归
    void con(int i,int j);
    int connection();           //求连通块数，非递归
};

bool matrix::m_set()
{
    for(int i=0;i<row;++i)
    {
        int t;
        vector<int> vt;
        for(int j=0;j<col;++j)
        {
            cin >> t;
            vt.push_back(t);
        }
        v.push_back(vt);
    }
    return true;
}

int matrix::connect()
{
    vector< vector<int> > t=v;
    int k=0;
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            if(v[i][j])
            {
                con(i,j);
                ++k;
            }
    v=t;
    return k;
}

void matrix::con(int i,int j)
{
    int t=v[i][j];
    v[i][j]=0;
    if(j>0 && t==v[i][j-1])      //左
        con(i,j-1);
    if(j+1<col && t==v[i][j+1]) //右
        con(i,j+1);
    if(i>0 && t==v[i-1][j])        //上
        con(i-1,j);
    if(i+1<row && t==v[i+1][j])  //下
        con(i+1,j);
}

int matrix::connection()
{
    int k=0;
    vector< vector<int> > vt=v;
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            if(v[i][j]==0) continue;

            stack<point> s;
            point p;
            p.x=i;
            p.y=j;
            s.push(p);
            int t=v[i][j];                  //此连通块元素的值

            while(!s.empty())
            {
                p=s.top();
                v[p.x][p.y]=0;
                if(p.y>0 && t==v[p.x][p.y-1])       //左
                {
                    p.y=p.y-1;
                    s.push(p);
                    continue;
                }
                if(p.y+1<col && t==v[p.x][p.y+1])   //右
                {
                    p.y=p.y+1;
                    s.push(p);
                    continue;
                }
                if(p.x>0 && t==v[p.x-1][p.y])       //上
                {
                    p.x=p.x-1;
                    s.push(p);
                    continue;
                }
                if(p.x+1<row && t==v[p.x+1][p.y])   //下
                {
                    p.x=p.x+1;
                    s.push(p);
                    continue;
                }
                s.pop();
            }
            ++k;
        }
    }
    v=vt;
    return k;
}

int main()
{
    int m,n;
    while(cin >> m >> n)
    {
        matrix M(m,n);
        if(M.m_set())
            cout << M.connection() << endl;
    }
    return 0;
}
