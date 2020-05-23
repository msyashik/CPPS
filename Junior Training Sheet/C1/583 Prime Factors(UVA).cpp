#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100000005

vector<ll>prime;
char sieve[SIZE];
vector<ll>factors;

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

void factorize(ll n)
{
	ll sqrtn = sqrt(n);
	for(ll i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		//if(sieve[n] == 0) break;
		if(n%prime[i] == 0)
		{
			while(n%prime[i] == 0)
			{
				n /= prime[i];
				factors.push_back(prime[i]);
			}
			sqrtn = sqrt(n);
		}
	}
	if(n != 1)
	{
		factors.push_back(n);
	}
	printf("%lld",factors[0]);
	for(ll i = 1; i < (ll)factors.size();i++)
	{
		cout << " x " << factors[i];
	}
	printf("\n");
	factors.clear();
}




int main()
{
	isprime(1000000);	
	ll n;
	
	while(scanf("%lld",&n) == 1)
	{
		if(n == 0) return 0;
		if( n== -1) {printf("%lld = -1\n",n);continue;}
		else if(n < 0) printf("%lld = -1 x ",n);
		else printf("%lld = ",n);
		factorize(abs(n));
	}
	return 0;
}
