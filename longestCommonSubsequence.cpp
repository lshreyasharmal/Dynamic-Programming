#include <bits/stdc++.h>
using namespace std;
string lcs(int n,int m,string str1,string str2)
{
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout <<"length of longest common subsequence is: "<< dp[n][m] << endl;
    cout <<"longest common subsequence is: ";
    string ans = "";

    int i= n,j=m;
    while( !(i==0 || j==0))
    {
        if(dp[i][j]!=dp[i-1][j] && dp[i][j]!=dp[i][j-1])
        {
            ans+=str1[i-1];
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j])
            i--;

        else if(dp[i][j]==dp[i][j-1])
            j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
int main()
{
    string str1,str2;
    cin >>str1>>str2;
    int n = str1.size();
    int m = str2.size();
    cout << lcs(n,m,str1,str2) << endl;
    return 0;
}
