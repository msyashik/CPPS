#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool isprime(ll n)
{
	ll sqrtn = sqrt(n);
	for(ll i = 2; i <= sqrtn; i++)
	{
		if(n%i == 0) return false;
	}
	return true;
}

ll func(ll n, ll po)
{
	if(po == 0) return 1;
	if(po&1)
	{
		return n*func(n,po-1);
	}
	else
	{
		ll curr = func(n,po/2);
		return curr*curr;
	} 
}

int main()
{	
	ll n;
	while(scanf("%lld",&n) == 1)
	{
		if(n == 0) return 0;
		ll ans1 = func(2,n-1);
		ll ans2 = func(2,n) - 1;
		if(isprime(ans1) || isprime(ans2))
		{
			printf("Perfect: %lld!\n",ans1*ans2);
		}
		else if(isprime(n))
		{
			printf("Given number is prime. But, NO perfect number is available.\n");
		}
		else
		{
			printf("Given number is NOT prime! NO perfect number is available.\n");
		}
	}
}
