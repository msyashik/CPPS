#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int arr[30005], n, t, dist[30005], path[30005];
bool vis[30005];
int start, mx = 0;
vector<pair<int,int>>v[30005];
map<int,int>mp;
int flag = 0, p1, p2;

void dfs(int node, int val)
{
    vis[node] = 1;
    if(val > mx)
    {
		mx = val;
		start = node;
	}
    int len = v[node].size();
    for(int i = 0; i < len ;i++)
    {
		int child = v[node][i].first;
		int cost = v [node][i].second;
		if(!vis[child]) 
		{
			if(flag) path[child] = node;
		    dfs(child, val+cost);
		}
	}
}

void dfs2(int node, int val)
{
	vis[node] = 1;
	
	if(node == start) dist[start] = 0;
	else if(mp.count(node))
	{
		dist[node] = max(val,mx-val);
	}
	else dist[node] = val;
	int len = v[node].size();
	for(int i = 0; i < len;i++)
	{
		int child = v[node][i].first;
		int cost = v[node][i].second;
		if(!vis[child]) 
		{
			if(mp.count(child)) dfs2(child, val+cost);
		    else dfs2(child, dist[node]+cost);
		}
	}
}

void path_search(int node)
{
	mp[node]++;
	if(node == p1) return;
	int prev = path[node];
	path_search(prev);
}

int main()
{
	scanf("%d", &t);
	for(int kase = 1; kase <= t;kase++)
	{
		scanf("%d", &n);
		n--;
		for(int i = 1; i <= n; i++)
		{
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			v[a].push_back({b,w});
			v[b].push_back({a,w});
		}
		mx = 0, flag = 0;
		dfs(0,0);
		p1 = start;
		for(int i = 0;i <= n;i++) vis[i] = 0;
	    mx = 0, flag = 1;
	    dfs(start, 0);
	    p2 = start;
	    path[p1] = p1;
	    path_search(p2);
	    for(int i = 0; i <= n; i++) vis[i] = 0;
	    dfs2(start, 0);
	    dist[start] = mx;
	    printf("Case %d:\n", kase);
	    for(int i = 0; i <=n; i++) 
	    {
	        printf("%d\n", dist[i]);
	        dist[i] = 0;
	        vis[i] = 0;
	        v[i].clear();
	        path[i] = i;
		}
		mp.clear();
	}
	return 0;
}
