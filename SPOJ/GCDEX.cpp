#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1000005

char sieve[SIZE];
vector<ll>v;
ll mx = 0;

void isprime()
{
	sieve[0] = 1;
	sieve[1] = 1;
	sieve[2] = 0;
	for(ll i = 4; i <= 1000000; i+=2)
	{
		sieve[i] = 1;
	}
	ll len = sqrt(1000000);
	for(ll i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= 1000000; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	v.push_back(2);
	for(ll i = 3; i <= 1000000; i+=2)
	{
		if(sieve[i] == 0) v.push_back(i);
	}
}

ll divisors(int n)
{
	ll sum = 1;
	int len = sqrt(n),m=n;
	
	for(int i = 0; i < v.size() && v[i] <= len; i++)
	{
		if(sieve[n] == 0) break;
		if(n%v[i] == 0)
		{
			ll ans = 1,coun = 0;
			while(n%v[i] == 0)
			{
				n /= v[i];
				coun++;
				ans *= v[i];
			}
			ll baki = ans/v[i];
			ans *= (coun+1);
			ans -= (coun*(baki));
			sum *= ans;
			len = sqrt(n);
		}
	}
	if(n != 1)
	{
		sum *= ((2*n) - (1));
	}
	return sum-m;
}

int main()
{	
	isprime();
	ll arr[1000005];
	
	arr[1] = 0;
	
	for(int i = 2; i <= 1000000; i++)
	{
		arr[i] = arr[i-1] + divisors(i);
	}
	
	int n;
	
	while(scanf("%d", &n) == 1)
	{
	    if(n == 0) return 0;
	   
		printf("%lld\n", arr[n]);
    }
	
	return 0;
}
