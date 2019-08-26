#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1000005

char sieve[SIZE];
vector<int>prime;

void isprime()
{
	sieve[0] = 1;
	sieve[1] = 1;
	sieve[2] = 0;
	
	for(int i = 4; i <= 1000000; i+=2) sieve[i] = 1;
	
	int len = sqrt(1000000);
	for(int i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(int j = i*i; j <= 1000000; j+=(2*i))
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3; i <= 1000000; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}
}


int divisors(int n)
{
	int len = sqrt(n),sum = 1;
	for(int i = 0; i < prime.size() && prime[i] <= len; i++)
	{
		if(sieve[n] == 0) break;
		if(n%prime[i] == 0)
		{
			int ans = 0;
			while(n%prime[i] == 0)
			{
				ans++;
				n /= prime[i];
			}
			ans++;
			len = sqrt(n);
			sum *= ans;
		}
	}
	if(n != 1)
	{
		sum *= 2;
	}
	return sum;
}

int main()
{
	isprime();
    
    vector<int>pq;
    
    for(int num = 1; num <= 1000000; num++)
    {
		int div = divisors(num);
		int f = 0;
		if(sieve[div] == 1)
		{
			int len = sqrt(div);
			for(int i = 0; i < prime.size() && prime[i] <= len; i++)
			{
				if(f == 1) break;
				if(div%prime[i] == 0 && (prime[i]*prime[i] != div))
				{
					int f = div/prime[i];
					if(sieve[f] == 0) {f = 1;pq.push_back(num);}
				}
			}
		}
	}
	
	for(int l = 8; l < pq.size(); l+=9)
	{
		printf("%d\n",pq[l]);
	}
	
    
	return 0;
}
