#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 10000005
#define mod 1000003

ll fact[1000005];

void func()
{
	fact[0] = 1;
	for(ll i = 1; i <= 1000000; i++)
	{
		fact[i] = ((i%mod)*(fact[i-1]%mod))%mod;
	}
}

ll bigmod(ll n, ll p)
{
	if(p == 0) return 1;
	else if(p == 1) return n;
	if(p%2 == 0)
	{
		ll ans = bigmod(n,p/2)%mod;
		return (ans%mod * ans%mod)%mod;
	}
	return (n%mod * bigmod(n,p-1)%mod)%mod;
}

int main()
{	
	func();
	ll t, n, r;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld %lld", &n,&r);
		printf("Case %lld: ", kase);
		if(n == r || r == 0) printf("1\n");
		else if(r == 1) printf("%lld\n",n);
		else
		{
		    ll up = fact[n];
		    ll down = (fact[n-r]%mod * fact[r]%mod);
		    ll ans = bigmod(down,mod-2);
		    ll ash = ((up%mod)*(ans%mod))%mod;
		    printf("%lld\n",ash);
		}
	}
	return 0;
}
//
