#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

ll n,m,l,r,val,ans[300005];
vector<ll>v;
set<ll>s;

int main()
{	
	IOS
	cin >>n >> m;
	for(ll i = 1; i <= n; i++) s.insert(i);
	for(ll i = 1; i <= m;i++)
	{
		cin >> l >> r >> val;
		auto it = s.lower_bound(l);
		while(it!=s.end())
		{
			ll curr = *it;
			if(curr > r) break;
			if(curr!=val)
			{
				v.push_back(curr);ans[curr] = val;
			}
			it++;
		}
		for(ll j = 0; j < (ll)v.size(); j++)
		{
			s.erase(v[j]);
		}
		v.clear();
	}
	for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
