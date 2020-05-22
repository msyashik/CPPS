#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll dp[1005][1005];
ll t,n,arr[55];
bool yes[55];

ll func(ll l, ll r)
{
	if(l >= r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	ll ans = 1e10;
	bool brk = false;
	for(ll i = 1; i <= n;i++)
	{
		if(arr[i] >= l && arr[i] <= r && yes[i] == false)
		{
			brk = true;
			yes[i] = true;
			ll curr = (r-l)+ 1 + func(l,arr[i]) + func(arr[i]+1,r);
			ans = min(curr,ans);
			yes[i] = false;
		}
	}
	if(!brk) return 0;
	return dp[l][r] = ans;
}

int main()
{	
	while(scanf("%lld",&t) == 1)
	{
		if(t == 0) return 0;
		scanf("%lld",&n);
		for(ll i = 1;i  <= n; i++)
		{
			scanf("%lld",&arr[i]);
		}
		memset(dp,-1,sizeof(dp));
		ll ans = func(1,t);
		printf("The minimum cutting is %lld.\n",ans);
	}
	return 0;
}
