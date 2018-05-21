/*
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？ 
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
*/
#include <iostream>

using namespace std;

const long long MAX = __LONG_LONG_MAX__;

int main()
{
    //输入
    int n,k,d;
    cin >> n;
    long long int* a = new long long int[n+1];
    for(int i=1;i<=n;++i)
        cin >> a[i];
    cin >> k >> d;
    
    //初始化
    long long ma[51][11];
    long long mi[51][11];
    for(int i=1;i<=n;++i)
    {
        ma[i][0] = 1;
        mi[i][0] = 1;
        for(int j=1;j<=k;++j)
        {
            ma[i][j] = -MAX;
            mi[i][j] = MAX;
        }    
    }

    long long ans = -MAX;
    for(int i=1;i<=n;++i)
    {
        ma[i][1]=a[i];
        mi[i][1]=a[i];
        if(k==1)
            ans=max(ans,a[i]);
    }

    //动态规划
    for(int i=2;i<=n;++i)
        for(int j=2;j<=k&&j<=i;++j)
        {
            for(int t=i-1;t>=max(1,i-d)&&t>=j-1;t--)
            {
                ma[i][j]=max(ma[i][j],ma[t][j-1]*a[i]);
                ma[i][j]=max(ma[i][j],mi[t][j-1]*a[i]);
                mi[i][j]=min(mi[i][j],ma[t][j-1]*a[i]);
                mi[i][j]=min(mi[i][j],mi[t][j-1]*a[i]);
            }
            if(j == k)
                ans = max(ans,ma[i][j]);
        }

    cout << ans << endl;
    delete [] a;
    return 0;
}
