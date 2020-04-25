#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 1005

vector<ll>prime;
char sieve[SIZE];

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

void factFactorize (ll n ) {
	ll coun = 0;
    for (ll i = 0; i < prime.size() && prime[i] <= n; i++ ) {
        ll x = n;
        ll freq = 0;
 
        while ( x / prime[i] ) {
            freq += x / prime[i];
            x = x / prime[i];
        }
        if(coun == 0)
        {
			printf ("%lld (%lld)", prime[i], freq);
			coun++;
		}
		else
		{
            printf (" * %lld (%lld)", prime[i], freq);
		}
    }
}

int main()
{
	isprime(1000);
	ll t, n;
	
	scanf("%lld",&t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld", &n);
		printf("Case %lld: %lld = ", kase,n);
		factFactorize(n);
		printf("\n");
	}
	
	return 0;
}

