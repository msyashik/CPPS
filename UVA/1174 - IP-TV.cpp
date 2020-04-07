#include <bits/stdc++.h>

using namespace std;

int par[2005], siz[2005];

int func(int p)
{
	if(par[p] == p) return p;
	return par[p] = func(par[p]);
}

void funca(int a, int b)
{
	a = func(a);
	b = func(b);
	if(a!=b)
	{
		if(siz[a] < siz[b]) swap(a,b);
		par[b] = a;
		siz[a]+=siz[b];
	}
}

int main()
{
	int t, n, m;
	
	cin >> t;
	for(int kase = 1; kase <= t; kase++)
	{
		cin >>n >>m;
		string ch, bh;
		int cost;
		map<string,int>mp;
		int coun = 0;
		vector<pair<int, pair<int,int>>>v;
		for(int i= 1; i  <= m; i++)
		{
			cin >> ch >> bh >> cost;
			if(mp.count(ch) == 0) 
			{
				coun++;
				mp.insert({ch,coun});
			}
			if(mp.count(bh) == 0) 
			{
				coun++;
				mp.insert({bh,coun});
			}
			int a = mp[ch], b = mp[bh];
			v.push_back({cost, {a,b}});
		}
		sort(v.begin(),v.end());
		for(int i = 1; i <= coun; i++) {par[i] = i;siz[i] = 1;}
		int len = v.size(), total = 0;
		for(int i = 0;i < len; i++)
		{
			int node1= func(v[i].second.first), node2 = func(v[i].second.second);
			
			if(node1 == node2) continue;
			else
			{
				funca(v[i].second.first,v[i].second.second);
				total += v[i].first;
			}
		}
		if(kase == 1) cout  << total << endl;
		else cout << endl << total << endl;
		memset(par,0,sizeof(par));
		memset(siz,0,sizeof(siz));
		v.clear();mp.clear();
	}
	return 0;
}
