#include <bits/stdc++.h>
using namespace std;
bool subsetSum(vector<int>v,int n,int t)
{
    bool dp[n+1][t+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int i=1;i<=t;i++)
        dp[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            if(j<v[i-1])
                dp[i][j]=dp[i-1][j];
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
            }
        }
    }
    return dp[n][t];
}
int main()
{
    int n,t;
    cin >> n >> t;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << subsetSum(v,n,t) << endl;
    return 0;
}
