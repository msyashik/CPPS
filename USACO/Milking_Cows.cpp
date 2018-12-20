/*
 ID: mdshaha2
 LANG: C++11
 TASK: milk2
*/

#include <bits/stdc++.h>

#define ll long long 
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


using namespace std;

int main()
{
	IOS
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	
	ll c, d, n, a[5005], b[5005];
	vector< pair<ll, ll> > v;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++)
	{
		cin >> c >> d;
		v.pb(make_pair(c,d));
	}
	
	if(n == 1) cout << d-c << " " << 0 << "\n";
	else
	{
		sort(v.begin(), v.end());
		
		ll len = v.size();
		
		for(ll i = 0; i < len; i++)
		{
			a[i+1] = v[i].first;
			b[i+1] = v[i].second;
		}
		
		ll minn = a[1];
		ll maxx = b[1];
		ll sum, ans = 0;
		ll lminn = 0,add = 0;
		
		for(ll i = 2; i <= n; i++)
		{
			if(a[i] <= maxx)
			{
				if(b[i] > maxx) maxx = b[i];
				continue;
			}
			else
			{
				sum = maxx - minn;
				ans = max(sum, ans);
				
				add = a[i] - maxx;
				lminn = max(add,lminn);
				
				minn = a[i];
				maxx = b[i];
			}
		}
		
		sum = maxx - minn;
		ans = max(ans, sum);
		
		cout << ans << " " << lminn << "\n";
	}
	
	v.clear();
	
	return 0;
}
