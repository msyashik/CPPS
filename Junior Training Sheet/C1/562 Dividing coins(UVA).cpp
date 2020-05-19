#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll n, arr[105], dp[105][50005];

ll func(ll indx, ll f, ll s)
{
	if(indx > n)
	{
		return abs(f-s);
	}
	else if(dp[indx][f] != -1) return dp[indx][f];
	ll p = min(func(indx+1,f+arr[indx],s),func(indx+1,f,s+arr[indx]));
	return dp[indx][f] = p;
}

void solve()
{	
	scanf("%lld", &n);
	for(ll i =1 ; i <= n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	memset(dp,-1,sizeof(dp));
	ll ans = func(1,0,0);
	printf("%lld\n",ans);
	
}


int main()
{
	ll t;
	
	scanf("%lld", &t);
	while(t--)
	{
		solve();
	}
	return 0;
}
