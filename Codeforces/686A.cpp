#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
	int n,x,a;
	char ch;
	ll sum = 0,coun = 0;
	
	cin >> n >> x;
	sum+=x;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> ch >> a;
		if(ch == '+') sum += a;
		else
		{
			if(sum >= a)
			{
				sum -= a;
			}
			else coun++;
		}
	}
	
	cout << sum << " " << coun << endl;
	
	return 0;
}
