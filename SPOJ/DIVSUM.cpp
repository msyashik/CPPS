#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

void divisors(int n)
{
	ll sum = 0;
	int len = sqrt(n);
	
	for(int i = 2; i <= len; i++)
	{
		if(n%i == 0)
		{
			if(n/i == i)
			{
				sum += i;
			}
			else
			{
			    sum+=i;
				sum+=n/i;
			}
		}
	}
	cout << sum+1 << endl;
}


int main()
{
	int t,n;
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		if(n == 1) cout << 0 << endl;
		else divisors(n);
	}
	
		
	return 0;
}
