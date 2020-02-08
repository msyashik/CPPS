#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define SIZE 20005

//SCC

vector<int>v[SIZE], rev[SIZE], sg[SIZE];
stack<int>s;
bool vis[SIZE];
int val = 0, comp[SIZE], indeg[SIZE],outdeg[SIZE];

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

int main()
{
	int t, n,m;
	
	scanf("%d",&t);
	for(int kase = 1; kase <= t; kase++)
	{
		val = 0;
	    scanf("%d %d", &n,&m);
	    for(int i = 1; i <= m; i++)
	    {
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			rev[b].push_back(a);
		}
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i]) dfs(i);
		}
		memset(vis,0,sizeof(vis));	
		
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
		
		
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i]) sg_dfs(i);
		}
		memset(vis,0,sizeof(vis));
		
		for(int i = 1; i <= val; i++)
		{
			int sg_len = sg[i].size();
			outdeg[i] = sg_len;
			for(int j = 0; j < sg_len; j++)
			{
				indeg[sg[i][j]]++;
			}
		}
		int in = 0, out = 0;
		for(int i = 1; i <= val; i++)
		{
			if(indeg[i] == 0) in++;
			if(outdeg[i] == 0) out++;
		}
		int ash = max(in,out);
		if(val == 1) ash = 0;
		printf("Case %d: %d\n", kase, ash);
		
		for(int i = 1; i <= n; i++)
		{
			vis[i] = 0;
			v[i].clear();
			rev[i].clear();
			sg[i].clear();
			comp[i] = 0;
			indeg[i] = 0;
			outdeg[i] = 0;
		}
	}
    return 0;	
}
