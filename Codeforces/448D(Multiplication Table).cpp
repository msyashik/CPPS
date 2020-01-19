#include <bits/stdc++.h>

using namespace std;
 
#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

ll r, c, k;

bool func(ll p)
{
	ll len = min(r,p);
	ll sum = 0;
	for(ll i = 1;i <= len; i++)
	{
		ll man = min(p/i, c);
		sum += man;
	}
	if(sum >= k) return true;
	else return false;
}

int main()
{	
	scanf("%lld %lld %lld", &r, &c, &k);
	ll low = 1, hi = k, mid;
	while(low < hi)
	{
		mid = (low+hi)/2;
		bool ans = func(mid);
		if(ans) 
		{
		    hi = mid;
		}
		else low = mid + 1;
	}
	cout << hi<< endl;
	return 0;
}
