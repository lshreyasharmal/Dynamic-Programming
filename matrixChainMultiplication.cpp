#include <bits/stdc++.h>
using namespace std;

int matrixChainMul(int n,vector<int> v)
{
    int dp[n][n];
    for(int i=0;i<n-1;i++)
        dp[i][i]=0;
    for(int l = 2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k = i;k<=j-1;k++)
            {
                q = dp[i][k] + dp[k+1][j] + v[i-1]*v[k]*v[j];
                if(q<dp[i][j])
                    dp[i][j]=q;
            }
        }
    }
    return dp[1][n-1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n-1;i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << matrixChainMul(n,v) << endl;
    return 0;
}
