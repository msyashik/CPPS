#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);

int main()
{
	ll n, a, b;
	
	while(scanf("%lld %lld %lld", &n,&a,&b) == 3)
	{
		unordered_map<ll,ll>mp;
		mp[0]++;
		ll x = 0;
		while(1)
		{
			ll rest = (a%n*(x%n*x%n)%n)%n;
			ll rest2 = b%n;
			x = (rest+rest2)%n;
			mp[x]++;
			ll val = mp[x];
			if(val == 3) break;
		}
		ll coun = 0;
		for(auto it : mp)
		{
			if(it.second >= 2) coun++;
		}
		cout << n-coun<< endl;
	}
	return 0;
}
