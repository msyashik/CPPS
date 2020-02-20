#include <bits/stdc++.h>

using namespace std;

#define ll long long 

vector<int>v[10005];
bool vis[10005];
int tin[10005], low[10005], timer = 0;
map<pair<int,int>,int>mp;

void IS_Bridge(int n1, int n2)
{
	mp[{n1,n2}]++;
}
void dfs(int node, int par)
{
	vis[node] = 1;
    timer++;
    tin[node] = low[node] = timer;	
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
			if(low[child] > tin[node])
			{
				int f = min(node,child);
				int l = max(node,child);
				IS_Bridge(f, l);
			}
		}
	}
}

int main()
{
	int t, n;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
		    int a, b, c;
		    scanf("%d (%d)",&a, &b);
		    for(int j = 1; j <= b; j++)
		    {
				scanf("%d", &c);
				v[a].push_back(c);
			}
		}
		timer = 0;
	    for(int i = 0; i < n; i++)
	    {
		    if(!vis[i]) dfs(i,-1);
	    }
	    printf("Case %d:\n", kase);
	    int ans = mp.size();
	    printf("%d critical links\n", ans);
	    for(auto it : mp)
	    {
			printf("%d - %d\n",it.first.first,it.first.second);
		}
	    for(int i = 0; i < n; i++)
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
