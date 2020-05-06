#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

vector<ll>prime;
char sieve[10000004];
ll ans1,ans2,len;

void isprime(ll n)
{
    sieve[0] = 1,sieve[1] = 1;
    sieve[2] = 0;
    for(ll i =4; i <= n; i+=2) sieve[i] = 1;
    for(ll i = 3; i <= sqrt(n); i+=2)
    {
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= n; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}	
	prime.push_back(2);
	for(ll i = 3; i <= n; i+=2) 
	{
	    if(sieve[i] == 0) prime.push_back(i);
	}
}

bool func(ll n)
{
	for(ll i = 0; i < len && prime[i] <= n; i++)
	{
		ll res = abs(n-prime[i]);
		if(sieve[res] == 0)
		{
			ans1 = prime[i];
			ans2 = res;
			return true;
		}
	}
	return false;
}

int main()
{
	ll n;
	isprime(10000000);
	len = prime.size();
	while(scanf("%lld", &n) == 1)
	{
		if(n <= 7) 
		{
			printf("Impossible.\n");
			continue;
		}
		ll tr = false;
		for(ll i = 4; i <= (n+1)/2; i++)
		{
			ll f = i;
			ll l = n-i;	
			ll a,b,c,d;
			bool yes1 = false,yes2 = false;
			if(func(f))
			{
				a = ans1;b = ans2;
				yes1 = true;
			}
			if(func(l))
			{
				c = ans1;d = ans2;
				yes2 = true;
			}
			if(yes1 && yes2)
			{
				tr = true;
				printf("%lld %lld %lld %lld\n", a,b,c,d);
				break;
			}
		}
		if(!tr) printf("Impossible.\n");
	}
	
	return 0;
}
