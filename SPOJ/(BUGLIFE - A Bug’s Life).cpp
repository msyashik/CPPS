#include <bits/stdc++.h>

using namespace std;

int des[2005];
int f = 0;
vector<int>v[2005];

void dfs(int node, int color)
{
	if(f == 1) return;
	des[node] = color;
	 
	int len = v[node].size();
	
	for(int i = 0; i < len; i++)
	{
		int nodd = v[node][i];
	
		if(color == 1 && des[nodd] == 1)
		{
			f = 1;
			return;
		}
		else if(color == 2 && des[nodd] == 2)
		{
			f = 1;
			return;
		}
		else if(color == 1 && des[nodd] == 0)
		{
			dfs(nodd,2);
		}
		else if(color == 2 && des[nodd] == 0)
		{
			dfs(nodd,1);
		}
		if(f == 1) break;
	} 
	return;
}

int main()
{
	int t, a, b, n, m;
	
	cin >> t;
	
	for(int kase = 1; kase <= t; kase++)
	{
		cin >> n >> m;
		for(int j = 1; j <= m; j++)
		{
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		f = 0;
		
		memset(des, 0, sizeof(des));
		
		for(int i = 1; i <= n; i++)
		{
			if(des[i] == 0)
			{
				dfs(i,1);
			}
			v[i].clear();
		}
		cout << "Scenario #" << kase<<":\n";
		if(f == 1) cout <<  "Suspicious bugs found!\n";
		else cout << "No suspicious bugs found!\n";
	}
	
	return  0;
}
