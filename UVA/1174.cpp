#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<pair<int,pair<int,int>>>v;
int par[2005];
int sum = 0;

int find(int r)
{
	if(par[r] == r) return r;
	else return par[r] = find(par[r]);
} 

void unions1(int a, int b, int take)
{
	int u = find(a);
	int v = find(b);
	
	if(u != v)
	{
		par[v] = u;
		sum += take;
	}
}

int main()
{  
	map<string,int>mp;
	int t, a, b, n, e, cost;
	string ch,bh;
	
	cin >> t;
	
	for(int kase = 1; kase <= t; kase++)
	{
		
	cin >> n >> e;
	
	for(int i = 1; i <= n; i++) 
	{
	    par[i] = i;
	}
	
	int coun = 1;
	sum = 0;
	for(int i = 1; i <= e; i++)
	{
		cin >> ch >> bh >> cost;
		
		if(mp.count(ch) == 0)
		{
			mp.insert({ch,coun});
			coun++;
		}
		if(mp.count(bh) == 0)
		{
			mp.insert({bh,coun});
			coun++;
		}
		
		a = mp[ch];
		b = mp[bh];
		
		v.push_back(make_pair(cost, make_pair(a,b)));
	}
	
	sort(v.begin(), v.end());
	
	int len = v.size();
	
	for(int i = 0; i < len; i++)
	{
		int a1 = v[i].second.first;
		int b1 = v[i].second.second;
		int k = v[i].first;
		
		unions1(a1,b1,k);
	}
	
	if(kase != t) cout << sum << endl << endl;
	else cout << sum << endl;
	mp.clear();
	v.clear();
    }
	return 0;
}
