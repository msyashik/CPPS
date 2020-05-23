#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool isprime(ll n)
{
	for(ll i = 2;i<=sqrt(n);i++)
	{
		if(n%i == 0) return false;
	}
	return true;
}

void fact(ll n)
{
	ll mx = 0;
	bool yes = false;
	for(ll i = 2;; i++)
	{
		ll ans = 1;
		if(i*i > n) break;
		for(ll j = 1;; j++)
		{
		    ans*=i;
		    if(ans == n)
		    {
				yes = true;
				mx = max(j,mx);
				break;
			}
		    if(ans > n) break;	
		}
	}
	if(yes) printf("%lld\n",mx);
	else printf("1\n");
}

void fact2(ll n)
{
	ll mx = 0;
	n = abs(n);
	bool yes = false;
	for(ll i = 2; ; i++)
	{
		ll ans = 1;
		if(i*i > n) break;
		for(ll j = 1;;j++)
		{
			ans*=i;
			if(ans == n && j%2) {mx = max(mx,j);yes = true;}
			if(ans > n) break;
		}
	}
	if(yes) printf("%lld\n",mx);
	else printf("1\n");
}

int main()
{
	ll n;
	while(scanf("%lld",&n) == 1)
	{
		if(n == 0) return 0;
		if(isprime(abs(n)))
		{
			printf("1\n");
		}
		else
		{
			if(n> 0)fact(n);
			else fact2(n);
		}
	}
	return 0;
}
