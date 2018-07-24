#include <bits/stdc++.h>
using namespace std;
int coin_change_ways(int n,int t,int a[])
{
    int dp[n+1][t+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int j=1;j<=t;j++)
        dp[0][j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            if(j>=a[i-1])
                dp[i][j] = dp[i][j-a[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][t];
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int t;
    cin >> t;
    cout << coin_change_ways(n,t,a) << endl;
    return 0;
}
