#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define inf 100000000

char sieve[SIZE];
vector<int>prime;

struct edges
{
	int div;
	int num;
};

bool operator < (edges a, edges b)
{
	if(a.div == b.div) return a.num < b.num;
	return a.div > b.div;
}

priority_queue<edges>pq;

void isprime()
{
	sieve[0] = 1;
	sieve[1] = 1;
	sieve[2] = 0;
	
	for(int i = 4; i <= 1000; i+=2) sieve[i] = 1;
	
	int len = sqrt(1000);
	for(int i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(int j = i*i; j <= 1000; j+=(2*i))
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3; i <= 1000; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}
}


void divisors(int n)
{
	int m = n;
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
	
	pq.push({sum,m});
}

int main()
{
	isprime();

	for(int i = 1; i <= 1000; i++)
	{
		divisors(i);
	}
	vector<int>v;
	while(!pq.empty())
	{
		int top = pq.top().num;
		pq.pop();
		v.push_back(top);
	}
	
	int t,p;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d", &p);
		printf("Case %d: %d\n",kase,v[p-1]);
	}
	
	return 0;
}
