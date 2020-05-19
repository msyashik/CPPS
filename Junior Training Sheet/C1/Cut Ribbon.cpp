#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll dp[4005];
ll n,a,b,c;

ll func(ll val)
{
	if(val >= n)
	{
		if(val == n) return 0;
		return -1*100000;
	}
	if(dp[val] != -1) return dp[val];
	ll ans1 = 0,ans2 = 0,ans3 = 0;
	ans1 = 1 + func(val+a);
	ans2 = 1 + func(val+b);
	ans3 = 1 + func(val+c);
    return dp[val] = max(ans1,max(ans2,ans3));
}

void solve()
{	
	scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
	memset(dp,-1,sizeof(dp));
	ll ans = func(0);
	cout<< ans << endl;
}

int main()
{
	solve();
	return 0;
}
