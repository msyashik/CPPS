#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI acos(-1.0)

ll dp[105][105005];
ll n, w, weight[105], cost[105];

ll func(ll indx, ll rest)
{
	if(indx > n) 
	{
		if(rest == 0) return 0;
		else return 10000000000;
	}
	if(rest == 0) return 0;
	if(dp[indx][rest] != -1) return dp[indx][rest];
	
	ll ans1 = 10000000000, ans2 = 10000000000;
	if(rest-cost[indx] >= 0)
	{
	    ans1 = weight[indx] + func(indx+1,rest-cost[indx]);
	}
	ans2 = func(indx+1,rest);
	return dp[indx][rest] = min(ans1,ans2); 
}


int main()
{
	
	scanf("%lld %lld", &n, &w);
	for(ll i = 1;i <= n; i++) scanf("%lld %lld", &weight[i],&cost[i]);
	memset(dp,-1,sizeof(dp));
	for(ll i = 100000; i >= 0; i--)
	{
		ll ans = func(1,i);
		if(ans <= w)
		{
			printf("%lld\n",i);
			break;
		}
	}
	return 0;
}
