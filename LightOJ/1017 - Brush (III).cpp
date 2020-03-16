#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

ll dp[105][105][105];
ll t, n, w, m;
vector<ll>v;

ll func(ll indx, ll move, ll total)
{
	if(indx >= n)  return total;
	if(move >= m) return total;
	
	if(dp[indx][move][total] != -1) return dp[indx][move][total];
	
	ll len = upper_bound(v.begin(),v.end(),v[indx]+w) - (v.begin()+indx);
	ll ans1 = func(indx+(len),move+1,total+len);
	ll ans2 = func(indx+1,move,total);
	return dp[indx][move][total] = max(ans1,ans2);
}

int main()
{
	scanf("%lld", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%lld %lld %lld",&n, &w, &m);
		for(int i =1 ; i <= n; i++)
		{
			ll a, b;
			scanf("%lld %lld", &a, &b);
			v.push_back(b);
		}
		sort(v.begin(),v.end());
		memset(dp,-1,sizeof(dp));
		ll ans = func(0,0,0);
		printf("Case %d: %lld\n",kase,ans);
		v.clear();
	}
	return 0;
}
