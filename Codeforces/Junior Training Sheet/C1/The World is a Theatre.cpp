//Problem Link: https://codeforces.com/contest/131/problem/C

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

ll dp[105][105];

ll func(ll n, ll r)
{
	if(n == r) return 1;
	else if(r == 1) return n;
	if(dp[n][r] != -1) return dp[n][r];
	return dp[n][r] = func(n-1,r-1) + func(n-1,r);
}


int main()
{
	
	memset(dp,-1,sizeof(dp));
	
	ll n, m, t;
	
	cin >> n >> m >> t;
	
	ll total = 0;
	
	for(ll i = 1; i <= m; i++)
	{
		ll res1 = t-i;
		if(res1 <= n && res1 >=  4)
		{
			ll curr1 = func(n,res1)*func(m,i);
			total += curr1;
		}
	}
	
	cout << total << endl;
}
