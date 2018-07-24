#include <bits/stdc++.h>
using namespace std;

int kadanes(int a[],int n, int* start,int* end)
{
	// int curr_max = 0;
	// int max_so_far = INT_MIN;
	// int localstart = 0;
	// *end = -1;
	// for(int i=0;i<n;i++)
	// {
	// 	curr_max += a[i];
	// 	if(curr_max<0)
	// 	{
	// 		curr_max = 0;
	// 		localstart = i+1;
	// 	}
	// 	else if(curr_max > max_so_far)
	// 	{
	// 		max_so_far = curr_max;
	// 		*start = localstart;
	// 		*end = i;
	// 	}
	// }
	// if(*end!=-1)
	// 	return max_so_far;
	// *start = *end = 0;
	// max_so_far = a[0];
	// for(int i=1;i<n;i++)
	// {
	// 	if(a[i]>max_so_far)
	// 	{
	// 		max_so_far = a[i];
	// 		*start = *end = i;
	// 	}
	// }
	// return max_so_far;
	int max_so_far = a[0];
	int curr_max = a[0];
	*start = 0;
	*end = 0;
	for(int i=1;i<n;i++)
	{
		curr_max = max(curr_max+a[i],a[i]);
		max_so_far = max(max_so_far,curr_max);
		if(max_so_far == a[i])
		{
			*start = i;
			*end = i;
		}
		else if(max_so_far == curr_max)
		{
			*end = i;
		}
		
	}
	return max_so_far;
}

int max_sum_rect(vector<vector<int> >a,int n,int m)
{
	
	int l,r;
	int maxleft,maxright,maxup,maxdown;
	int maxsum = INT_MIN;
	l = 0;
	r = 0;
	for(l=0;l<m;l++)
	{
		int temp[n];
		memset(temp,0,sizeof(temp));
		for(r=l;r<m;r++)
		{
			for(int i=0;i<n;i++)
				temp[i]+=a[i][r];
			
			int start, end;
			int max_so_far = kadanes(temp,n,&start,&end);
			if(maxsum < max_so_far)
			{
				maxsum = max_so_far;
				maxleft = l;
				maxright = r;
				maxup = start;
				maxdown = end;
			}
		}
	}

	cout << "Up : " << maxup << endl;
	cout << "Down : " << maxdown << endl;
	cout << "Left : " << maxleft << endl;
	cout << "Right : " << maxright << endl;
	return maxsum;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int> >a;
	for(int i=0;i<n;i++)
	{
		vector<int> b;
		for(int j=0;j<m;j++)
		{
			int g;
			cin >> g;
			b.push_back(g);
		}
		a.push_back(b);
		
	}
	cout << "ierh" << endl;
	cout << max_sum_rect(a,n,m) << endl;
	return 0;
}