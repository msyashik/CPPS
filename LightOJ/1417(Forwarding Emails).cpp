#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define SIZE 50005

//SCC

vector<int>v[SIZE], rev[SIZE], sg[SIZE];
stack<int>s;
bool vis[SIZE];
int val = 0, comp[SIZE], dp[SIZE];
map<int,int>mp;
set<int>st[SIZE];

//Creating the stack from the given graph
void dfs(int node)
{
	vis[node] = 1;
	int len = v[node].size();
	for(int i = 0; i < len ;i++)
	{
		int child = v[node][i];
		if(!vis[child]) dfs(child);
	}
	s.push(node);
}

//making components 
void rev_dfs(int node)
{
	vis[node] = 1;
	comp[node] = val;
	int len = rev[node].size();
	for(int i = 0; i < len; i++)
	{
		int child = rev[node][i];
		if(!vis[child])
		{
			rev_dfs(child);
		}
	}
}

//making super graph
void sg_dfs(int node)
{
	vis[node] = 1;
	mp[comp[node]]++;
	st[comp[node]].insert(node);
	int len = v[node].size();
	for(int i = 0; i < len; i++)
	{
		int child = v[node][i];
		if(!vis[child])
		{
			int a = comp[node];
			int b = comp[child];
			if(a!=b) sg[a].push_back(b);
			sg_dfs(child);
		}
		else
		{
			int a = comp[node];
			int b = comp[child];
			if(a!=b) sg[a].push_back(b);
		}
	}
}
//super graph traversing
int new_dfs(int node)
{
	vis[node] = 1;
	int len = sg[node].size();
	int mx = 0;
	for(int i = 0; i < len; i++)
	{
		int child = sg[node][i];
		if(!vis[child])
		{
			mx = max(mx,new_dfs(child));
		}
		else
		{
			mx = max(mx,dp[child]);
		}
	}
	dp[node] = mx+mp[node];
	return dp[node];
}
int main()
{
	int t, n;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
	val = 0;
	scanf("%d", &n);
	for(int i= 1; i<= n; i++)
    {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		rev[b].push_back(a);
	}
	
	for(int i = 1;i <= n; i++)
	{
		if(!vis[i]) dfs(i);
	}
	memset(vis, 0, sizeof(vis));
	
	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		if(!vis[top])
		{
			val++;
			rev_dfs(top);
		}
	}
	memset(vis,0,sizeof(vis));
	
	for(int i =1; i<=n; i++)
	{
		if(!vis[i]) sg_dfs(i);
	}
	memset(vis,0,sizeof(vis));
	

	int ans = 0;
	for(int i = 1; i <= val; i++)
	{
	    if(!vis[i]) ans = max(ans,new_dfs(i));	
	}
	memset(vis, 0, sizeof(vis));
	
	int ash = INT_MAX;
	for(int i = 1; i <=val; i++)
	{
		int tot = dp[i];
		if(tot == ans)
		{
			ash = min(ash, *st[i].begin());
		}
	}
	printf("Case %d: %d\n", kase, ash);
	
	for(int i =1; i <= n; i++)
	{
		comp[i] = 0;
		v[i].clear();
		rev[i].clear();
		sg[i].clear();
		st[i].clear();
		dp[i] = 0;
	}
	mp.clear();
    }
    return 0;	
}
