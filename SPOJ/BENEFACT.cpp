#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll dist[50005];
int mx_node;
ll mx;
bool visited[50005];

struct edges
{
	int v;
	ll w;
};

void bfs(int node, vector<edges>v[])
{
	dist[node] = 0;
	visited[node] = 1;
	queue<edges>q;
	q.push({node,0});
	
	while(!q.empty())
	{
		edges top = q.front();
		q.pop();
		
		int len = v[top.v].size();
		
		for(int i = 0; i < len; i++)
		{
			edges nodd = v[top.v][i];
			if(visited[nodd.v] == 0)
			{
				visited[nodd.v] = 1;
				dist[nodd.v] = dist[top.v] + nodd.w;
				q.push(nodd);
				
				if(dist[nodd.v] > mx)
				{
					mx = dist[nodd.v];
					mx_node = nodd.v;
				}
				
			}
		}
	}
	
}

int main()
{
	int t,n, a, b;
	ll cost;
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		vector<edges>v[n+1];
		
		for(int i = 1; i <= n-1; i++)
		{
			scanf("%d %d %lld", &a, &b, &cost);
			v[a].push_back({b,cost});
			v[b].push_back({a,cost});
			dist[i] = 0;
			visited[i] = 0;
		}
		dist[n] = 0;
		visited[n] = 0;
		mx_node = 0;
		mx = 0;
		
		bfs(1, v);
		
		
		for(int i = 1; i <= n; i++)
		{
			dist[i] = 0;
			visited[i] = 0;
		}
		
		mx = 0;
		
	    if(mx_node != 0) 
	    {
	        bfs(mx_node, v);
	        printf("%lld\n",mx);
		}
		else printf("0\n");
	}
	
	return 0;
}
