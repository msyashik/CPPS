#include <bits/stdc++.h>

using namespace std;

#define ll long long 

vector<int>v[10005];
bool vis[10005];
int tin[10005], low[10005], timer = 0;
map<int,int>mp;

void IS_AP(int node)
{
	mp[node]++;
}
void dfs(int node, int par)
{
	vis[node] = 1;
    timer++;
    tin[node] = low[node] = timer;	
    int children = 0;
    int len = v[node].size();
    for(int i = 0; i < len; i++)
    {
		int child = v[node][i];
		if(child == par) continue;
		if(vis[child])
		{
			low[node] = min(low[node],tin[child]);
		}
		else
		{
			dfs(child,node);
			low[node] = min(low[node], low[child]); 
			if(low[child] >= tin[node] && par != -1)
			{
				IS_AP(node);
			}
			children++;
		}
	}
	if(par == -1 && children > 1) IS_AP(node);
}

int main()
{
	int t, n, m;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; i++)
		{
		    int a, b;
		    scanf("%d %d",&a, &b);
		    v[a].push_back(b);
		    v[b].push_back(a);	
		}
		timer = 0;
	    for(int i = 1; i <= n; i++)
	    {
		    if(!vis[i]) dfs(i,-1);
	    }
	    int ans = mp.size();
	    printf("Case %d: %d\n", kase, ans);
	    for(int i = 1; i <= n; i++)
	    {
			vis[i] = 0;
			v[i].clear();
			tin[i] = -1;
			low[i] = -1;
		}
		mp.clear();
	}
	return 0;
}
