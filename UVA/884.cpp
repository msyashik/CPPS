#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1000005
 
char sieve[SIZE];
vector<int>prime;

 
void primeSieve()
{
	sieve[0] = 1;
	sieve[1] = 1;
	for(int i = 4; i <= 1000000; i+=2) sieve[i] = 1;
	int len = sqrt(1000000);
	for(ll i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= 1000000; j += 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(ll i = 3; i <= 1000000; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}
}
 
int divisors(int n)
{
	int len = sqrt(n),sum = 0;
	for(int i = 0; i < prime.size() && prime[i] <= len ; i++)
	{
		if(n%prime[i] == 0)
		{
			while(n%prime[i] == 0)
			{
				sum++;
				n /= prime[i];
			}
			len = sqrt(n);
		}
	}
	if(n != 1)
	{
		sum += 1;
	}
	return sum;
} 
 
int main()
{
	primeSieve();
	
	int dp[1000005];
	dp[1] = 0;
	
	for(int i = 2; i <= 1000000; i++)
	{
	    if(sieve[i] == 0)
	    {
			dp[i] = dp[i-1] + 1;
		}
		else
		{
			dp[i] = dp[i-1] + divisors(i);
		}	
	}
	
	int t;
	
	while(scanf("%d",&t) == 1)
	{
		 printf("%d\n", dp[t]);
	}
	
	return 0;
}
