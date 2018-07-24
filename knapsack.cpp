#include <bits/stdc++.h>
using namespace std;
int knapsack(int n,int w,vector<int> weights,vector<int> values)
{
    int dp[n+1][w+1];

    for(int i=0;i<n+1;i++)
        dp[i][0]=0;
    for(int j=0;j<w+1;j++)
        dp[0][j]=0;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(weights[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],values[i-1]+dp[i-1][j-weights[i-1]]);
        }
    }
    return dp[n][w];
}
int main()
{
    int n,w;
    cin >> n >> w;
    vector<int> weights,values;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        weights.push_back(a);
        values.push_back(b);
    }

    cout << knapsack(n,w,weights,values) << endl;
    return 0;
}
