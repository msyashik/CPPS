#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int n, m, arr[1005], cost[1005][1005];
vector<int>v1[1005];
int par[1005],  vis[1005], sum = 0, coun = 0, root;

int find_set(int v)
{
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}
void union_set(int a, int b, int costt)
{
	int aa = find_set(a);
	int bb = find_set(b);
	if(aa!=bb)
	{
		if(bb == b)
		{
			v1[a].push_back(b);
			v1[b].push_back(a);
			par[b] = a;
			root = a;
		    sum += costt;
		}
	}
}
void dfs(int node)
{
	coun++;
	vis[node] = 1;
	int len = v1[node].size();
	for(int i = 0; i < len; i++)
	{
		int child = v1[node][i];
		if(!vis[child]) dfs(child);
	}
}
int main()
{	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) 
		{
			cost[i][j] = 1000000005;
		}
	}
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	scanf("%d", &m);
	map<pair<int,int>,int>mp;
	while(m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		mp.insert({{a,b},1});
		cost[a][b] = min(cost[a][b],c);
	}
	vector<pair<int, pair<int,int>>>v;
	for(auto it : mp)
	{
		int a = it.first.first;
		int b = it.first.second;
	    v.push_back({cost[a][b], {a,b}});
	}
	sort(v.begin(), v.end());
	for(int i =1 ; i <=n; i++)
	{
		par[i] = i;
		vis[i] = 0;
	}
	int len = v.size();
	for(int i = 0; i< len; i++)
	{
		int a = v[i].second.first;
		int b = v[i].second.second;
		int costt = v[i].first;
		
		//cout << a << " " << b << " " << costt << endl;
		
		union_set(a,b,costt);
	}
	dfs(root);
	if(coun == n) cout << sum << endl;
	else cout << -1 << endl;
	return 0;
}
