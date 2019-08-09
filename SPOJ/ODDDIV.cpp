#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100005
 
char sieve[SIZE];
vector<ll>prime;
vector<ll>v[10005];

void primeSieve()
{
	sieve[0] = 1;
	sieve[1] = 1;
	for(int i = 4; i <= 100000; i+=2) sieve[i] = 1;
	int len = sqrt(100000);
	for(ll i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= 100000; j += 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(ll i = 3; i <= 100000; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}
}
 
void divisors(ll n)
{
	ll m = n;
	int len = sqrt(n),total = 1;
	
	for(int i = 0; i < prime.size() && prime[i] <= len ; i++)
	{
		if(n%prime[i] == 0)
		{
			int coun = 0;
			while(n%prime[i] == 0)
			{
				coun++;
				n /= prime[i];
			}
			total *= (2*coun + 1);
			len = sqrt(n);
		}
	}
	if(n != 1)
	{
		total *= 3;
	}
	v[total].push_back((ll)m * (ll)m);
}
 
int main()
{
	primeSieve();
	
	for(int i = 1; i <= 100000; i++)
	{
		divisors(i);
	}
	
	int t,k;
	ll low,high;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %lld %lld", &k, &low, &high);
		
		int len1 = lower_bound(v[k].begin(), v[k].end(), low) - v[k].begin();
		int len2 = upper_bound(v[k].begin(), v[k].end(), high) - v[k].begin();
		
		len2--;
		
		cout <<len2-len1+1<< endl;
	}
	return 0;
}
