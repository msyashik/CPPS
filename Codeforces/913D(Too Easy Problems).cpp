#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
 
ll n, tim, a[200005], t[200005];
vector<pair<ll,ll>>v;
vector<ll>pos,ash;
ll sum = 0;
 
bool func(ll val)
{
	v.clear();
	pos.clear();
	for(ll i = 1; i <= n; i++) 
	{
		if(a[i] >= val) 
		{
			v.push_back({t[i],i});
		}	
	}
	ll len = v.size();
	if(len < val) return false;
	sort(v.begin(), v.end());
	ll summ = 0;
	for(ll i = 0; i < len; i++)
	{
		if(((summ+v[i].first) > tim) || (pos.size() == val)) break;
		else
		{
			summ += v[i].first;
			pos.push_back(v[i].second);
		}
	}
	ll len2 = pos.size();
	if(len2 < val) return false;
	ash = pos;
	return true;
}
 
int main()
{	
	
	ll coun = 0;
	
	scanf("%lld %lld", &n, &tim);
	for(ll i = 1; i <= n; i++)
	{
		scanf("%lld %lld", &a[i], &t[i]);
		if(t[i] > tim) coun++;
	}
	if(coun == n)
	{
		cout << 0 << endl << 0 << endl;
		return 0;
	}
	ll low = 1, hi = 200000, mid;
	while(low <= hi)
	{
		mid = (low+hi)/2;
		bool ans = func(mid);
		if(ans) {sum = max(sum,mid);low = mid + 1;}
		else hi = mid-1;
	}
	cout << sum << endl;
	ll ashln = ash.size();
	cout << ashln << endl;
	for(int i = 0; i < ashln; i++)
	{
		cout << ash[i] << " ";
	}
	cout << endl;
	return 0;
}
