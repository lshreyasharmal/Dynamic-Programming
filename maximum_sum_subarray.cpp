#include <bits/stdc++.h>
using namespace std;
void max_subarray(int a[],int n)
{
	int max_so_far = a[0];
	int curr_max = a[0];
	for(int i=1;i<n;i++)
	{
		curr_max = max(curr_max+a[i],a[i]);
		max_so_far = max(max_so_far,curr_max);
	}
	cout << max_so_far << endl;
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	max_subarray(a,n);
	return 0;
}