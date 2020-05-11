#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);

void solve()
{
	ll n, p, sum = 0;
	
	cin >> n >> p;
	sum = (2*n)+p;
	ll coun = 0;
	for(ll i = 1; i <= n-1; i++)
	{
		if(coun == sum) break;
		for(ll j = i+1; j <= n; j++)
		{
			if(sum == coun) break;
			else
			{
				cout << i << " "<< j << endl;
				coun++;
			}
		}
	}
}


int main()
{
	ll t;
	
	cin >> t;
	while(t--)
	{
		solve();
	}
}
