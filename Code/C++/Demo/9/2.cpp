#include <iostream>
#include <vector>

using namespace std;

class matrix
{
private:
    int row;
    int* index;             //每行元素的个数
    vector< vector<int> > v;
public:
    matrix():row(0),index(NULL){}
    matrix(const vector< vector<int> > & cv);
    matrix(const matrix & m);
    ~matrix();
    int getdata(int i,int j) const;
    int getrow() const;
    int getindex(int i) const;
    matrix operator + (matrix & m);
    matrix & operator = (matrix m);
    void display() const;
};

matrix::matrix(const vector< vector<int> > & cv)
{
    v=cv;
    row=cv.size();
    index=new int[row];
    for(int i=0;i<row;++i)
        index[i]=v[i].size();
}

matrix::matrix(const matrix & m)
{
    row=m.getrow();
    index=new int[row];
    for(int i=0;i<row;++i)
    {
        index[i]=m.getindex(i);
        vector<int> t;
        for(int j=0;j<index[i];++j)
            t.push_back(m.getdata(i,j));
        v.push_back(t);
    }
}

matrix::~matrix()
{
    delete [] index;
}

int matrix::getdata(int i,int j) const
{
    if(i<0||i>=row||j<0||j>=index[i]) return 0;
    return v[i][j];
}

int matrix::getrow() const
{
    return row;
}

int matrix::getindex(int i) const
{
    if(i<0||i>=row) return 0;
    return index[i];
}

matrix  matrix::operator + (matrix & m)
{
    matrix t(*this);
    for(int i=0;i<row;++i)
        for(int j=0;j<index[i];++j)
            v[i][j]+=m.getdata(i,j);
    matrix temp(*this);
    *this=t;
    return temp;
}

matrix & matrix::operator = (matrix m)
{
    if(&m==this) return *this;
    (*this).~matrix();
    row=m.getrow();
    index=new int[row];
    for(int i=0;i<row;++i)
    {
        index[i]=m.getindex(i);
        vector<int> t;
        for(int j=0;j<index[i];++j)
            t.push_back(m.getdata(i,j));
        v.push_back(t);
    }
    return *this;
}

void matrix::display() const
{
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<index[i];++j)
        {
            if(j) cout << " ";
            cout << v[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void v_set(const int row,const int* const index,vector< vector<int> > & v)
{
    int n;
    for(int i=0;i<row;++i)
    {
        vector<int> t;
        for(int j=0;j<index[i];++j)
        {
            cin >> n;
            t.push_back(n);
        }
        v.push_back(t);
    }
}

int main()
{
    int row,n;
    vector< vector<int> >  v1,v2;
    cin >> row;
    int* index=new int[row];
    for(int i=0;i<row;++i)
    {
        cin >> n;
        index[i]=n;
    }
    v_set(row,index,v1);
    v_set(row,index,v2);
    matrix m1(v1);
    matrix m2(v2);
    cout << endl;
    m1.display();
    m2.display();
    matrix m3=m1+m2;
    m3.display();
    delete [] index;
    return 0;
}
