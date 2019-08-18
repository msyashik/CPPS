#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<int>v[20005];
int visited[10005];
int f = 0;

void dfs(int node, int par)
{
	visited[node] = 1;
	int len = v[node].size();
    	
	for(int i = 0; i < len; i++)
	{
		if(f == 1) return;
		int nodd = v[node][i];
		if(visited[nodd] == 0)
		{
			dfs(nodd,node);
		}
		else if(par!=nodd)
		{
			f = 1;
			return;
		}
	}
	return;
}

int main()
{
	int n,e,a,b;
	
	scanf("%d %d",&n,&e);
	
	for(int i = 1; i <= e; i++)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
    for(int i = 1; i<= n; i++)
    {
		if(f == 1) break;
		if(visited[i] == 0)
		{
			dfs(i,0);
		}
	}	
	
	if(f == 0) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
