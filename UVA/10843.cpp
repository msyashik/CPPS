#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define mod  2000000011

ll t, n;

ll func(ll p, ll pow)
{
	if(pow == 0) return 1;
	
	if(pow%2 == 0)
	{
		ll ans = func(p, pow/2);
		
		return ((ans%mod)*(ans%mod)) % mod;
	}
	else 
	{
		return ((p%mod)*(func(p, pow-1)%mod))%mod;
	}
	
}

int main()
{
	cin >> t;
	
	for(int kase = 1; kase <= t; kase++)
	{
		cin >> n;
		
		if(n == 1 || n == 2) cout << "Case #" << kase << ": " << 1 << endl;
		
		else
		{
		    ll ans = func(n,n-2);
		
		    cout << "Case #" << kase << ": " << ans << endl;
		}
	}
	
	
	return 0;
}
