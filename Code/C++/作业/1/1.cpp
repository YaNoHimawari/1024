#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int* p=(int*)malloc(sizeof(int)*n*n);
    for(int i=0;i<n*n;i++)
        p[i]=0;

    int row=0,col=n/2,k=1;
    p[row*n+col]=k;
    while(++k<=n*n)
    {
        int a=row,b=col;
        if(--a<0) a=n-1;
        if(++b>=n) b=0;
        if(p[a*n+b])
        {
            if((a=row+1)>=n) a=0;
            b=col;
        }
        p[a*n+b]=k;
        row=a; col=b;
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
        cout.width(5);
        cout << left << p[i*n+j];
        }
        cout << endl;
    }

    free(p);
    system("pause");

    return 0;
}
