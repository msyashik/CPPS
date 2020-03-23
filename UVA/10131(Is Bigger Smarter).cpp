#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define mod 100000007
#define MAXN 100000
//
int main()
{
	ll w,q;
	vector<pair<ll,pair<ll,ll>>>v;
	int coun = 0;
	while(scanf("%lld %lld", &w, &q)==2)
	{
		coun++;
		v.push_back({w,{q,coun}});
	}
	sort(v.begin(),v.end());
	ll len = v.size()-1;
	ll L[1005];
	for(ll i = 0; i <= len; i++)
	{
		L[i] = 1;
	}
	for(ll i = 0; i <= len ;i++)
	{
		for(ll j = i + 1 ;j <= len ;j++)
		{
			if(v[j].first > v[i].first && v[j].second.first < v[i].second.first)
			{
				L[j] = max(L[j],L[i]+1);
			}
		}
	}
	ll ans = 0,indx, weight,iq;
	for(ll i = 0; i <= len ; i++)
	{
		if(L[i] > ans)
		{
			ans = L[i];
			indx = v[i].second.second;
			weight = v[i].first;
			iq = v[i].second.first;
		}
	}   
	vector<ll>ash;
	ash.push_back(indx);
	ll curr = ans-1;   
	for(ll i = len ;i>= 0; i--)
	{
		if(curr == 0) break;
		if(L[i] == curr && weight > v[i].first && iq < v[i].second.first)
		{
			curr--;
			weight = v[i].first;
			iq = v[i].second.first;
			ash.push_back(v[i].second.second);
		}
	}
	reverse(ash.begin(),ash.end());
	printf("%lld\n",ans);
	for(ll i = 0; i < ans; i++) printf("%lld\n",ash[i]);
	return 0;
}
