#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int p = 100000000, prime[10000000];
vector<int>v;

bool check(int n, int x)
{
	int mask = (1 << x);
	int res = (n&mask);
	if(res == 0) return 0;
	else return 1;
}

int Set(int n, int x)
{
    int mask = (1 << x);
    int res = (n | mask);
    return res;	
}

void primeSieve(int n) 
{
	int len = sqrt(n);
	
	for(int i = 3; i <= len; i+=2)
	{
		if(check(prime[i>>5], i%32) == 0)
		{
			for(int j = i*i; j <= n; j += 2*i)
			{
				prime[j>>5] = Set(prime[j>>5], j%32);
			}
		}
	}
	
	v.push_back(2);
	
	for(int i = 3; i <=  p;i+=2)
	{
		if(check(prime[i>>5], i%32) == 0)
		{
			v.push_back(i);
		}
	}
}

int main()
{	
	primeSieve(p);
	
	int t, k;
	
	cin >> t;
	
	while(t--)
	{
		cin >> k;
		cout << v[k-1] << endl;
	}
	
		
	return 0;
}
