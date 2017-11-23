#include <iostream>
#include <cmath>

using namespace std;

class matrix
{
private:
    int* m;
    int row,col;
public:
    matrix(int x,int y)
    {
        row=x;
        col=y;
        m=new int[row*col];
    }
    matrix(const matrix & M);
    ~matrix(){delete [] m;}
    int getrow() const {return row;}
    int getcol() const {return col;}
    int getdata(int i,int j) const {return m[i*col+j];}
    void m_set(int i,int j,int data);
    matrix & operator = (const matrix & M);
    matrix submatrix(int x,int y,int a,int b);
    int m_abs(const matrix & M);
};

matrix::matrix(const matrix & M)
{
    row=M.getrow();
    col=M.getcol();
    m=new int[row*col];
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            m[i*col+j]=M.getdata(i,j);
}

void matrix::m_set(int i,int j,int data)
{
    m[i*col+j]=data;
}

matrix & matrix::operator=(const matrix & M)
{
    if(this==&M) return *this;
    (*this).~matrix();

    row=M.getrow();
    col=M.getcol();
    m=new int[row*col];
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            m[i*col+j]=M.getdata(i,j);
    return *this;
}

matrix matrix::submatrix(int x,int y,int a,int b)
{
    if(x<0||y<0||x>row-a||y>col-b) return *this;
    matrix t(a,b);
    for(int i=0;i<a;++i)
        for(int j=0;j<b;++j)
            t.m_set(i,j,m[(i+x)*col+j+y]);
    return t;
}

int matrix::m_abs(const matrix & M)
{
    if(row!=M.getrow()||col!=M.getcol())
        return -1;
    int sum=0;
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            sum+=abs(m[col*i+j]-M.getdata(i,j));
    return sum;
}

int main()
{
    int m1,n1,data;
    cin >> m1 >> n1;
    matrix M1(m1,n1);
    for(int i=0;i<m1;++i)
        for(int j=0;j<n1;++j)
        {
            cin >> data;
            M1.m_set(i,j,data);
        }

    int m2,n2;
    cin >> m2 >> n2;
    matrix M2(m2,n2);
    for(int i=0;i<m2;++i)
        for(int j=0;j<n2;++j)
        {
            cin >> data;
            M2.m_set(i,j,data);
        }

    int minabs;
    int minrow[100]={0};
    int mincol[100]={0};
    int length=0;
    for(int i=0;i<=m1-m2;++i)
        for(int j=0;j<=n1-n2;++j)
        {
            matrix t=M1.submatrix(i,j,m2,n2);
            int temp=t.m_abs(M2);
            if(temp==-1)
                continue;
            else if(i==0&&j==0)
            {
                ++length;
                minabs=temp;
            }
            else if(minabs==temp)
            {
                minrow[length]=i+1;
                mincol[length]=j+1;
                ++length;
            }
            else if(minabs>temp)
            {
                length=0;
                minrow[length]=i+1;
                mincol[length]=j+1;
                ++length;
                minabs=temp;
            }
        }

    cout << minabs << endl;
    for(int i=0;i<length;++i)
        cout << "<" << minrow[i] << "," << mincol[i] << ">";
    return 0;
}
