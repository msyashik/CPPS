#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

vector<ll>prime;
char sieve[20000004];

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

int main()
{
	ll n;
	
	isprime(20000000);
	ll len = prime.size();
	vector<pair<ll,ll>>v;
	for(ll i = 1; i < len; i++)
	{
		if(prime[i]-prime[i-1] == 2)
		{
			v.push_back({prime[i-1],prime[i]});
		}
	}
	
	while(scanf("%lld", &n) == 1)
	{
		printf("(%lld, %lld)\n", v[n-1].first,v[n-1].second);
	}
	return 0;
}
