#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define SIZE 1005

//SCC(Strongly Connected Component)

vector<int>v[SIZE], rev[SIZE], sg[SIZE];
stack<int>s;
bool vis[SIZE];
int val = 0, comp[SIZE];

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
	}
}
int main()
{
	int n, e;
	
	scanf("%d %d", &n, &e);
	for(int i= 1; i<= e; i++)
    {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		rev[b].push_back(a);
	}
	
	//traversing over the given graph
	for(int i = 1;i <= n; i++)
	{
		if(!vis[i]) dfs(i);
	}
	memset(vis, 0, sizeof(vis));
	
	//traversing over the reverse graph using the stack elements 
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
	
	/*for(int i =1; i <= n; i++)
	{
		cout << comp[i] << " ";
	}
	cout << endl;*/
	
	for(int i =1; i<=n; i++)
	{
		if(!vis[i]) sg_dfs(i);
	}
	memset(vis,0,sizeof(vis));
	
	for(int i =1; i <= val ; i++)
	{
		cout<< i <<": ";
		for(int j = 0; j < (int) sg[i].size(); j++)
		{
			cout << sg[i][j] << " ";
		}
		cout << endl;
	}
	for(int i =1; i <= n; i++)
	{
		comp[i] = 0;
		v[i].clear();
		rev[i].clear();
		sg[i].clear();
	}
    return 0;	
}
