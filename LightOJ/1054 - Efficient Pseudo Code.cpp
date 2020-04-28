#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 10000005
#define mod 1000000007

vector<ll>prime;
char sieve[SIZE];

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
	for(int i = 3; i <= n; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}	
}

ll bigmod(ll n, ll p)
{
    if(p == 0) return 1;
    else if(p == 1) return n%mod;
    else if(p%2 == 0)
    {
		ll ans = bigmod(n,p/2)%mod;
		return ((ans%mod)*(ans%mod))%mod;
	}	
	return ((n%mod)*(bigmod(n,p-1)%mod))%mod;
}


void SOD(ll n, ll q)
{
	ll sqrtn = sqrt(n);
	ll res = 1;
	for(ll i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		if(n%prime[i] == 0)
		{
			ll coun = 0;
			while(n%prime[i] == 0)
			{
				n /= prime[i];
				coun++;
			}
			sqrtn = sqrt(n);
			ll ans = bigmod(prime[i],(coun*q)+1);
			ll ans2 = bigmod(prime[i]-1,mod-2);
			ll ans3 = (((ans-1+mod)%mod)*((ans2+mod)%mod))%mod;
			res = ((res%mod)*(ans3%mod))%mod;
		}
	}
	if(n != 1)
	{
			ll ans = bigmod(n,q+1);
			ll ans2 = bigmod(n-1,mod-2);
			ll ans3 = (((ans-1+mod)%mod)*((ans2+mod)%mod))%mod;
			res = ((res%mod)*(ans3%mod))%mod;
	}
	printf("%lld\n",res);
}

int main()
{		
	isprime(10000000);
	ll t, p, q;
	
	scanf("%lld", &t);
	for(ll kase = 1 ;kase <= t; kase++)
	{
		scanf("%lld %lld", &p, &q);
		printf("Case %lld: ", kase);
		SOD(p,q);
	}
	return 0;
}
