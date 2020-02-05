#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

ll n , m, mod;

ll func(ll a, ll b)
{
	if(b == 0) return 1;
	if(b%2 == 0)
	{
		ll f = func(a,b/2);
		return (((f%mod) * (f%mod))%mod + mod)%mod;
	}
	return (((a%mod) * (func(a,b-1)%mod))%mod + mod)%mod;
}

int main()
{
	while(scanf("%lld %lld %lld", &n, &m, &mod) == 3)
	{
		ll anss = func(n,m);
		printf("%lld\n", anss);
	}
	return 0;
}
