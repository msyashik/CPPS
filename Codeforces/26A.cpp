#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int total = 0;
int prime[3005];

void func()
{
	prime[0] = 1;
	prime[1] = 1;
	
	for(int i = 4; i <= 3000; i+=2) prime[i] = 1;
	
	for(int i = 3; i <= 3000; i+=2)
	{
		if(prime[i] == 0)
		{
			for(int j = i*i; j <= 3000; j+=2*i)
			{
			    prime[j] = 1;
			}
		}
	}
}


void divisors(int n)
{
	int coun = 0;
	int len = sqrt(n);
	
	for(int i = 2; i <= len; i++)
	{
		if(n%i == 0)
		{
			if(n/i == i)
			{
				if(prime[i] == 0) coun++;
			}
			else
			{
				if(prime[i] == 0) coun++;
				if(prime[n/i] == 0) coun++;
			}
		}
	}
	if(coun == 2) total++;
}


int main()
{
	func();
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		if(prime[i] == 1)
		{
			divisors(i);
		}
	}
	
	cout << total << endl;
	
	return 0;
}
