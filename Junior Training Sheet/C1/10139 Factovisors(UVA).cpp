#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100000005

vector<int>prime;
char sieve[SIZE];
vector<int>factors;
map<int,int>mp1,mp2;

void isprime(int n)
{
    sieve[0] = 1,sieve[1] = 1;
    sieve[2] = 0;
    for(int i =4; i <= n; i+=2) sieve[i] = 1;
    for(int i = 3; i <= sqrt(n); i+=2)
    {
		if(sieve[i] == 0)
		{
			for(int j = i*i; j <= n; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3; i <= n; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}	
}

void factorize(int n)
{
	int sqrtn = sqrt(n);
	for(int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		//if(sieve[n] == 0) break;
		if(n%prime[i] == 0)
		{
			while(n%prime[i] == 0)
			{
				n /= prime[i];
				factors.push_back(prime[i]);
			}
			sqrtn = sqrt(n);
		}
	}
	if(n != 1)
	{
		factors.push_back(n);
	}
	for(int i = 0; i < (int)factors.size(); i++)
	{
		mp1[factors[i]]++;
	}
}

int factorial_fact(int n, int p)
{
    int x = n;
    int freq = 0;
    while ( x / p)
    {
         freq += x / p;
         x = x / p;
    }
    return freq;
}

int32_t main()
{
	isprime(1000000);	
	
	int a, b;
	
	while(cin >> a >> b)
	{
		if(a == 0)
		{
			if(b == 1) cout << b << " divides " << a << "!\n";
			else cout << b << " does not divide " << a << "!\n";
			continue;
		}
		mp1.clear();
		mp2.clear();
		factors.clear();
		
		factorize(b);
		bool yes = true;
		for(auto it : mp1)
		{
			int num = it.first , freq = it.second;
			int ans = factorial_fact(a, num);
			if(ans < freq) 
			{
				yes = false;
				break;
			}
		}
		if(yes) cout << b << " divides " << a << "!\n";
		else cout << b << " does not divide " << a << "!\n";
	}
	
	return 0;
}
