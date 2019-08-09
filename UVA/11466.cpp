#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 10000005
 
char sieve[SIZE];
vector<ll>prime;

 
void primeSieve()
{
	sieve[0] = 1;
	sieve[1] = 1;
	for(int i = 4; i <= 10000000; i+=2) sieve[i] = 1;
	int len = sqrt(10000000);
	for(ll i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= 10000000; j += 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(ll i = 3; i <= 10000000; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}
}
 
void divisors(ll n)
{
	ll len = sqrt(n),coun = 0;
	ll mx = 0;
	for(int i = 0; i < prime.size() && prime[i] <= len ; i++)
	{
		if(n%prime[i] == 0)
		{
			coun++;
			mx = max(mx,prime[i]);
			while(n%prime[i] == 0)
			{
				n /= prime[i];
			}
			len = sqrt(n);
		}
	}
	if(n != 1)
	{
		coun++;
		mx = max(mx,n);
	}
	if(coun >= 2) cout << mx << endl;
	else cout << -1 << endl; ;
} 
 
int main()
{
	primeSieve();
	
	ll t;
	
	while(scanf("%lld", &t) == 1)
	{
		if(t == 0) break;
		divisors(abs(t));	
	}
	
	return 0;
}
