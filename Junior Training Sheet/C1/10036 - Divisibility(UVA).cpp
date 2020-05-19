#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll dp[10005][105];
ll n, k,arr[10005];

ll func(ll indx, ll mod)
{
	if(indx > n) return mod;
	if(dp[indx][mod] != -1) return dp[indx][mod];
	ll way1 = func(indx+1,((mod%k + arr[indx]%k) + k)%k);
	ll way2 = func(indx+1,((mod%k - arr[indx]%k) + k)%k);
	return dp[indx][mod] = min(way1,way2);
}

void solve()
{	
	scanf("%lld %lld", &n,&k);
	for(ll i = 1 ;i <= n; i++) scanf("%lld",&arr[i]);
	memset(dp,-1,sizeof(dp));
	ll ans = func(1,0);
	if(ans == 0) printf("Divisible\n");
	else printf("Not divisible\n");
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
