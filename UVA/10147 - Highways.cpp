#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int parent[1005];
int siz[1005];

int func(int p)
{
	if(parent[p] == p) return p;
	return parent[p] = func(parent[p]);
}

void dsu(int a, int b)
{
	a = func(a);
	b = func(b);
	if(a!=b)
	{
		if(siz[a] < siz[b]) swap(a,b);
		parent[b] = a; 
		siz[a] += siz[b];
	}
}

int main()
{	
	int test = 0, t, n, m,a[1005], b[1005];
	
	cin >> t;
	while(t--)
	{
		test++;
		vector<pair<double,pair<int,int>>>v;
		cin >> n;
		for(int i = 1; i<= n ;i++)
		{
			parent[i] = i;
			siz[i] = 1;
			cin >> a[i] >> b[i];
		}
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = i+1;j <= n; j++)
			{
				double f = abs(a[i]-a[j])*abs(a[i]-a[j]);
				double s = abs(b[i]-b[j])*abs(b[i]-b[j]);
				double ans = sqrt(f+s);
				v.push_back({ans,{i,j}});
			}
		}
		sort(v.begin(),v.end());
		cin >> m;
		for(int i = 1; i <= m; i++)
		{
			int f, s;
			cin >> f >> s;
			dsu(f,s);
		}
		int len = v.size();
		int coun = 0;
		if(test > 1) cout << "\n";
		for(int i = 0; i < len; i++)
		{
			int node1 = v[i].second.first, node2 = v[i].second.second;
			int par1 = func(node1), par2 = func(node2);
			if(par1 != par2)
			{
				coun++;
				dsu(node1,node2);
			    cout << node1 << " " << node2 << endl;
			}
		}
		if(coun == 0)
		{
			cout << "No new highways need\n";
		}
		v.clear();
	}
	
	
	return 0;
}
