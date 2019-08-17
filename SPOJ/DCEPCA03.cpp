#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 10005

char sieve[SIZE];
vector<ll>v;

void isprime()
{
	sieve[0] = 1;
	sieve[1] = 1;
	sieve[2] = 0;
	for(ll i = 4; i <= 10000; i+=2)
	{
		sieve[i] = 1;
	}
	ll len = sqrt(10000);
	for(ll i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= 10000; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	v.push_back(2);
	for(ll i = 3; i <= 10000; i+=2)
	{
		if(sieve[i] == 0) v.push_back(i);
	}
}

ll euler_phi(int n)
{
	ll sum = n;
	int len = sqrt(n);
	
	for(int i = 0; i < v.size() && v[i] <= len; i++)
	{
		if(sieve[n] == 0) break;
		if(n%v[i] == 0)
		{
			sum /= v[i];
			sum *= (v[i]-1);
			while(n%v[i] == 0)
			{
				n /= v[i];
			}
			len = sqrt(n);
		}
	}
	if(n != 1)
	{
		sum /= n;
		sum *= (n-1);
	}
	return sum;
}

int main()
{
	isprime();
	
	ll t, n, arr[10005];
	
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld", &n);
		ll sum = 0;
		for(int i = 1; i <= n; i++)
		{
			arr[i] = euler_phi(i);
			sum += arr[i];
		}
		ll man = 0;
		for(int i = 1; i<=n; i++)
		{
			man += (sum*arr[i]);
		}
		printf("%lld\n",man);
	}
	
	
	return 0;
}
