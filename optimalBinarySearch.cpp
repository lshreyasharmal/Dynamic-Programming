#include <bits/stdc++.h>
using namespace std;
int optimalBScost(int a[],int n)
{
    int dp[n][n];

    for(int i=0;i<n;i++)
        dp[i][i] = a[i];

}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << optimalBScost(a,n);
}
