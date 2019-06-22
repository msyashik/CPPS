//Problem Link : https://atcoder.jp/contests/abc131/tasks/abc131_b

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
int main()
{
	int arr[205], n, l;
	
	cin>> n >> l;
	
	int sum = 0;
	
	for(int i = 1; i <= n; i++)
	{
		arr[i] = l+i-1;
		sum +=arr[i];
	}
	
	int ans,mx, diff = INT_MAX;
	
	for(int i = 1; i <= n;i++)
	{
		ans = abs(sum - (sum-arr[i]));
		if(ans < diff) {diff = ans;mx = sum-arr[i];}
	}
	
	
	cout << mx << endl;
	return 0;
}
