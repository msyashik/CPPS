#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100000005

vector<ll>v1,v2;

/*char sieve[SIZE];
vector<ll>v;

void isprime()
{
	sieve[0] = 1;
	sieve[1] = 1;
	sieve[2] = 0;
	for(ll i = 4; i <= 100000000; i+=2)
	{
		sieve[i] = 1;
	}
	ll len = sqrt(100000000);
	for(ll i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= 100000000; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	v.push_back(2);
	for(ll i = 3; i <= 100000000; i+=2)
	{
		if(sieve[i] == 0) v.push_back(i);
	}
}

ll divisors(ll n)
{
	ll sum = 1;
	ll len = sqrt(n);
	
	for(int i = 0; i < v.size() && v[i] <= len; i++)
	{
		if(n%v[i] == 0)
		{
			ll ans = 1;
			while(n%v[i] == 0)
			{
				n /= v[i];
				ans++;
			}
			
			len = sqrt(n);
			sum *= ans;
		}
	}
	if(n != 1)
	{
		sum *= 2;
	}
	return sum;
	
}*/

void num_divisors(ll n)
{
	ll len = sqrt(n);
	
	for(ll i = 1; i <= len; i++)
	{
		if(n%i == 0)
		{
			if(n/i == i)
			{
				v1.push_back(i);
			}
			else
			{
				v1.push_back(i);
				v2.push_back(n/i);
			}
		}
	}
	reverse(v2.begin(), v2.end());
	
	
}
int main()
{	
	ll n,k;
	
	scanf("%lld %lld",&n, &k);
	
	num_divisors(n);
	int len1 = v1.size();
	int len2 = v2.size();
	
	if((len1+len2) >= k)
	{
		if(k <= len1)
		{
			printf("%lld\n", v1[k-1]);
		}
		else
		{
			k -=  len1;
			printf("%lld\n", v2[k-1]);
		}
	}
	else printf("-1\n");
	
    return 0;
    	
}
