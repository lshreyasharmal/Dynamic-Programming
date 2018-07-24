#include <bits/stdc++.h>
using namespace std;
int coin_change(int coins[],int n,int t)
{
   int dp[t+1];
   //0 coins needed to make a total sum of 0
   dp[0]=0;

   for(int i=1;i<t+1;i++)
    dp[i] = INT_MAX;
   for(int i=1;i<t+1;i++)
   {
       for(int j=0;j<n;j++)
           if(coins[j]<=i)
               dp[i] = min(dp[i],dp[i-coins[j]]+1);
   }
   return dp[t];
}
int main()
{
    int n;
    cin >> n;
    int coins[n];
    for(int i=0;i<n;i++)
        cin >> coins[i];
    int t;
    cin >> t;
    cout << coin_change(coins,n,t) << endl;
    return 0;
}
