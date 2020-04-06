//Inclusion-Exclusion Principle

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);
int main()
{
    ll t, n, m, p,q;
    
    cin >> t;
    while(t--)
    {
		cin >> n >> m >> p >> q;
		ll a = p, b = p+q,c = p+(2*q), d = p+(3*q), e = p+(4*q);
		ll ans = 0;
		ll arr[10];
		arr[1] = a, arr[2] = b,arr[3] = c, arr[4] = d, arr[5] = e;
		for(ll i = 1; i <= 5; i++)
		{
			ll l = (n-1)/arr[i];
			ll r = (m)/arr[i];
			ans += (r-l);
		}
		//cout << ans << endl;
		for(ll i = 1; i <= 5; i++)
		{
			for(ll j = i+1; j <= 5; j++)
			{
				ll val = (arr[i]*arr[j])/__gcd(arr[i],arr[j]);
				ll l = (n-1)/val;
				ll r = m/val;
				ans -= (r-l);
			}
		}
		//cout  << ans << endl;
		for(ll i = 1; i <= 5; i++)
		{
			for(ll j = i+1; j <= 5; j++)
			{
				for(ll k = j + 1; k <= 5; k++)
				{
					ll gc1 = __gcd(arr[i],arr[j]);
					ll lc1 = (arr[i]*arr[j])/gc1;
					ll gc2 = __gcd(lc1,arr[k]);
					ll lc2 = (lc1*arr[k])/gc2;
					
					ll val = lc2;
				    ll l = (n-1)/val;
				    ll r = m/val;
				    ans += (r-l);
				}
			}
		}
		for(ll i = 1; i <= 5; i++)
		{
			for(ll j = i+1; j <= 5; j++)
			{
				for(ll k = j + 1; k <= 5; k++)
				{
					for(ll z = k + 1; z <= 5; z++)
					{
						ll gc1 = __gcd(arr[i],arr[j]);
					    ll lc1 = (arr[i]*arr[j])/gc1;
					    ll gc2 = __gcd(lc1,arr[k]);
					    ll lc2 = (lc1*arr[k])/gc2;
					    ll gc3 = __gcd(lc2,arr[z]);
					    ll lc3 = (lc2*arr[z])/gc3;
						
						ll val = lc3;
				        ll l = (n-1)/val;
				        ll r = m/val;
				        ans -= (r-l);
					}
				}
			}
		}
		
		ll gc1 = __gcd(arr[1],arr[2]);
		ll lc1 = (arr[1]*arr[2])/gc1;
		ll gc2 = __gcd(lc1,arr[3]);
		ll lc2 = (lc1*arr[3])/gc2;
		ll gc3 = __gcd(lc2,arr[4]);
		ll lc3 = (lc2*arr[4])/gc3;
		ll gc4 = __gcd(lc3,arr[5]);
		ll lc4 = (lc3*arr[5])/gc4;
		
		ll val = lc4;
		ll l = (n-1)/val;
		ll r = m/val;
	    ans += (r-l);
		cout<< ((m-n) + 1) - ans << endl;
	}
	return 0;
}
