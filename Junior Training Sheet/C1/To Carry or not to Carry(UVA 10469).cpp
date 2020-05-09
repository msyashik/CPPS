#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

ll func(ll num, ll indx)
{
	ll mask = (1 << indx);
	ll res = (num&mask);
	if(res) return 1;
	else return 0;
}

int main()
{	
	ll a, b;
	
	while(scanf("%lld %lld", &a, &b) == 2)
	{
		vector<ll>v;
		for(ll i = 0;i < 32; i++)
		{
			ll ans1 = func(a,i);
			ll ans2 = func(b,i);	
			if(ans1 == 1 && ans2 == 1) v.push_back(0);
			else if(ans1 == 1 || ans2 == 1) v.push_back(1);
			else v.push_back(0);
		}
		reverse(v.begin(),v.end());
		ll ans = 0, mul = 1;
		for(ll i = (ll)v.size()-1; i>= 0; i--)
		{
			ans += (v[i]*mul);
			mul*=2;
		}
	    cout << ans << endl;
	    v.clear();
	}
	return 0;
}
