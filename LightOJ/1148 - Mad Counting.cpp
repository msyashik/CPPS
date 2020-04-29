#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define eps 1e-9

int main()
{
	ll t,n;
	map<ll,ll>mp;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld", &n);
		for(ll i = 1; i <= n; i++)
		{
			ll a;
			scanf("%lld", &a);
			mp[a]++;
		}
		ll sum = 0;
		for(auto it : mp)
		{
		    ll curr = it.first+1;
		    if(it.second%curr == 0) sum += it.second;
		    else
		    {
				sum += (((it.second/curr)+1)*curr);
			}
		}
		printf("Case %lld: %lld\n", kase, sum);
		mp.clear();
	}
	return 0;
}
