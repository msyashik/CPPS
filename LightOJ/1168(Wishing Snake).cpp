#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

//SCC

vector<int>v[10005], rev[10005], sg[10005];
stack<int>s;
bool vis[10005];
int comp[10005], val = 0, flag = 0, total = 0;

void dfs(int node)
{
	vis[node] = 1;
	int len = v[node].size();
	for(int i = 0; i < len; i++)
	{
		int child = v[node][i];
		if(!vis[child]) dfs(child);
	}
	s.push(node);
}

//making components
void dfs_rev(int node)
{
	vis[node] = 1;
	comp[node] = val;
	int len = rev[node].size();
	for(int i = 0; i < len; i++)
	{
		int child = rev[node][i];
		if(!vis[child]) dfs_rev(child);
	}
}

//building super graph
void sg_dfs(int node)
{
	vis[node] = 1;
	int len = v[node].size();
	for(int i = 0; i < len; i++)
	{
		int child = v[node][i];
		if(!vis[child])
		{
			int c1 = comp[node];
			int c2 = comp[child];
			if(c1!=c2) sg[c1].push_back(c2);
			sg_dfs(child);
		}
		else
		{
			int c1 = comp[node];
			int c2 = comp[child];
			if(c1 != c2) sg[c1].push_back(c2);
		}
	}
}

void last_dfs(int node)
{
	if(flag == 1) return;
	total++;
	vis[node] = 1;
	int len = sg[node].size();
	if(len >= 2)
	{
		flag = 1;
		return;
    }
	for(int i = 0; i < len; i++)
	{
		int child = sg[node][i];
		if(!vis[child]) 
		{
		    last_dfs(child);
		}
	}
}

int main()
{
	int t, n, m;
	
	scanf("%d", &t);
	for(int kase= 1; kase <= t; kase++)
	{
	    scanf("%d", &n);
	    map<int,int>mp;
	    val = 0, flag = 0, total = 0;
	    
	    for(int per = 1; per <= n; per++)
	    {
	    scanf("%d", &m);
	    mp[0]++;
	    for(int i = 1; i <= m; i++)
	    {
		    int a,b;
	        scanf("%d %d", &a, &b);
	        v[a].push_back(b);
	        rev[b].push_back(a);
	        mp[a]++;
	        mp[b]++;
	    }
	    }
	    for(auto it : mp)
	    {
		    if(!vis[it.first]) dfs(it.first);
	    }
	    memset(vis, 0, sizeof(vis));
	
	    while(!s.empty())
	    {
		    if(!vis[s.top()]) 
		    {
			    val++;
		        dfs_rev(s.top());
		    }
		    s.pop();
	    }
	    memset(vis, 0, sizeof(vis));
	
	    for(auto it : mp)
	    {
		    if(!vis[it.first]) sg_dfs(it.first);
	    }
	    memset(vis, 0, sizeof(vis));
	    last_dfs(comp[0]);
	    memset(vis, 0, sizeof(vis));
	    if(total != val) flag = 1;
		printf("Case %d: ", kase);
	    if(flag) printf("NO\n");
	    else printf("YES\n");
	    
	    for(auto it : mp)
	    {
			v[it.first].clear();
			rev[it.first].clear();
			sg[it.first].clear();
			comp[it.first] = -1;
		}
		for(int i = 1; i <= val; i++)
		{
			sg[i].clear();
		}
		mp.clear();
	}
	return 0;
}
