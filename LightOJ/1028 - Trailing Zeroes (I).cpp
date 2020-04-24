#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 1000005

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

//Number of Divisors(NOD)
void NOD(ll n)
{
	ll sqrtn = sqrt(n);
	ll res = 1;
	for(ll i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
	//	if(sieve[n] == 0) break; //if n is prime we can't factorize it anymore
		if(n%prime[i] == 0)
		{
			ll p = 0;
			while(n%prime[i] == 0)
			{
				n /= prime[i];
				factors.push_back(prime[i]);
				p++;
			}
			sqrtn = sqrt(n);
			p++;
			res *= p;
		}
	}
	if(n != 1)
	{
		factors.push_back(n);
		res *= 2;
	}
	cout << res-1 << endl;
}

int main()
{
	isprime(1e6);
	
	ll t, n;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld", &n);
		printf("Case %lld: ", kase);
		if(n == 1) {printf("0\n");continue;}
		NOD(n);
	}
	return 0;
}
//
