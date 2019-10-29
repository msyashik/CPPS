#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'

ll man,cost[1005],key[1005],dp[1005][9005];
ll n,m,a,b,c;
	
ll on(ll p, ll pos)
{
	ll ans = (1<<pos);
	p = (p|ans);
	return p;
}

ll func_dp(ll indx, ll val)
{
	if(indx > m)
	{
		if(val==man)
		{
			return 0;
		}
		else return 1e9;
	}
	
	if(dp[indx][val] != -1) return dp[indx][val];
	
	ll a1 = func_dp(indx+1,val|key[indx]) + cost[indx];
	ll a2 = func_dp(indx+1,val);
	
	return dp[indx][val] = min(a1,a2);
}

int main()
{	
	cin >> n >> m;
	
	man = (1 << n) - 1; 
	
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		cost[i] = a;
		ll bit = 0;
		for(int j = 1; j <= b; j++)
		{
			cin >> c;
			bit = on(bit,c-1);
		}
		key[i] = bit;
	}
	
	memset(dp,-1,sizeof(dp));
	
	ll ans = func_dp(1,0);
	
	if(ans >= 1e9) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}
