#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	ll n, k;
	
	cin >> n >> k;
	
	ll mid = (n+1)/2;
	
	if(k <= mid)
	{
		cout << (2*k)-1 << endl;
	}
	else
	{
		ll ans = k-mid;
		cout << (2*ans) << endl;
	}
	
	return 0;
}
