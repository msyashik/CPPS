#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define mod 100
#define MAXN 100000

ll n, arr[105];
pair<ll,ll>dp[105][105];
bool vis[105][105];

pair<ll,ll> func(ll beg, ll end)
{
	if(beg >= end) return {arr[beg],0};
	if(vis[beg][end]) return dp[beg][end];
	vis[beg][end] = 1;
	ll smoke =  10000000000000000;
	pair<ll,ll>ret;
	for(ll mid = beg; mid < end; mid++)
	{
		pair<ll,ll> left = func(beg,mid);
		pair<ll,ll> right = func(mid+1,end);
		ll total = (left.first%mod + right.first%mod)%mod;
		ll curr = (left.first*right.first) + left.second + right.second;
		if(curr < smoke)
		{
			smoke = curr;
			ret.first = total;
			ret.second = curr;
		}
	}
	return dp[beg][end] = ret;
}

int main()
{
	while(scanf("%lld", &n) == 1)
	{
	    for(ll i = 1; i <= n; i++)
	    {
		    scanf("%lld",&arr[i]);
		}
		memset(vis,0,sizeof(vis));
	    memset(dp,0,sizeof(dp));
	    pair<ll,ll> ans = func(1,n);
	    printf("%lld\n",ans.second);
	}
	return 0;
}
