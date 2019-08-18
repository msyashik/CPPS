#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 10005

char sieve[SIZE];
vector<int>v;

void isprime()
{
	sieve[0] = 1;
	sieve[1] = 1;
	sieve[2] = 0;
	for(int i = 4; i <= 10000; i+=2)
	{
		sieve[i] = 1;
	}
	int len = sqrt(10000);
	for(int i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(int j = i*i; j <= 10000; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	v.push_back(2);
	for(int i = 3; i <= 10000; i+=2)
	{
		if(sieve[i] == 0) v.push_back(i);
	}
}

void divisors(int n)
{
	int len = sqrt(n);
	int odd = 0, even = 0;
	
	for(int i = 0; i < v.size() && v[i] <= len; i++)
	{
		if(n%v[i] == 0)
		{
			int ans = 0;
			while(n%v[i] == 0)
			{
				n /= v[i];
				ans++;
			}
			len = sqrt(n);
			if(ans%2 == 1)odd++;
			else even++;
		}
	}
	if(n != 1)
	{
		odd++;
	}
	//cout << even << " " << odd << endl;
	if(even > odd) printf("Psycho Number\n");
	else printf("Ordinary Number\n");
}

int main()
{
	isprime();
	int t, n;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d",&n);
		divisors(n);
	}
	return 0;
}
