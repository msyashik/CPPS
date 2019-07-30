//Problem Link : https://atcoder.jp/contests/dp/tasks/dp_d

#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
 
ll v[105],weight[105],dp[105][100005],n,CAP;
 
ll KnapSack(int i, ll w)
{
	if(i == n)
	{
		return 0;
	}
	if(dp[i][w] != -1) return dp[i][w];
	ll ans1 = 0, ans2 = 0;
	if(w+weight[i] <= CAP)
	{
	    ans1 = KnapSack(i+1, w+weight[i]) + v[i];
	}
	ans2 = KnapSack(i+1, w);
	
	return dp[i][w] = max(ans1,ans2);
}
 
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> CAP;
	
	for(int i = 0; i < n; i++) cin >> weight[i] >> v[i];
	
	ll ans = KnapSack(0,0);
	
	cout << ans << endl;
	
	return 0;
}
