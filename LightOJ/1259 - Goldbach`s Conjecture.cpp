#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 10000005
#define eps 1e-9

vector<ll>prime;
char sieve[SIZE];
vector<ll>factors;//used for prime factorization

//checking prime or not
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
	isprime(10000000);
	
	ll t, n;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld", &n);
		ll coun = 0;
		for(ll j = 0; prime[j] <= (n+1)/2; j++)
		{
			if(sieve[n-prime[j]] == 0) coun++;
		}
		printf("Case %lld: %lld\n", kase, coun);	
	}
	return 0;
}
