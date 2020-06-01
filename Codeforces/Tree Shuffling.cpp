#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define double long double 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, cost[200005], curr[200005],lat[200005];
vector<int>v[200005];
bool vis[200005];
int x10 = 0, x01 = 0,total = 0;

pair<int,int> dfs(int node, int par, int pval)
{
	vis[node] = true;
	if(curr[node] == 1 && lat[node] == 0) x10++;
	else if(curr[node] == 0 && lat[node] == 1) x01++;
	int len = v[node].size();
	if(len == 1 && v[node][0] == par)
	{
		if(curr[node] == 1 && lat[node] == 0) return {1,0};
		else if(curr[node] == 0 && lat[node] == 1) return {0,1};
		else return {0,0};	
	}
	int nx10 = 0, nx01 = 0;
	for(int i = 0; i< len;i++)
	{
		int child = v[node][i];
		if(!vis[child])
		{
			pair<int,int>p = dfs(child,node,min(pval,cost[node]));
			nx10 += p.first;nx01 += p.second;
		}
	}
	if(curr[node] == 0 && lat[node] == 1) nx01++;
	else if(curr[node] == 1 && lat[node] == 0) nx10++;
	if(cost[node] <= pval)
	{
		int ans = min(nx10,nx01);
		total += (2*ans*cost[node]);
		return {nx10-ans,nx01-ans};
	}
	else
	{
		return {nx10,nx01};
	}
}

int32_t main()
{
	IOS
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> cost[i] >> curr[i] >> lat[i];
		vis[i] = false;
	}
	int a,b;
	for(int i = 1;i <= n-1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,-1,10000000000);
	
	if(x10 != x01)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << total << endl;
	return 0;
}
