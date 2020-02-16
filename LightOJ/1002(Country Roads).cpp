#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define endl '\n'
#define inf INT_MAX

vector<pair<int,int>>v[10005];
int t, n, m, dest, dist[10005];

void func()
{
	for(int i = 0; i < n; i++)
	{
        dist[i] = inf;		
	}
}

void dijkstra(int node)
{
    priority_queue<pair<int,int>>pq;
    pq.push({0,node});
    dist[node] = 0;	
    while(!pq.empty())
    {
		int top = pq.top().second;
		pq.pop();
		int len = v[top].size();
		for(int i = 0; i < len;i++)
		{
			int child = v[top][i].first;
			int vall = dist[child];
			if(dist[top] < v[top][i].second)
			{
				dist[child] = min(v[top][i].second, dist[child]);
			}
			else
			{
				dist[child] = min(dist[child], dist[top]);
			}
			if(vall!=dist[child])
			{
			    pq.push({-1*dist[child], child});
			}
		}
	}
}

int main()
{
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &n, &m);
		int a, b, w;
		while(m--)
		{
			scanf("%d %d %d", &a, &b, &w);
			v[a].push_back({b,w});
			v[b].push_back({a,w});
		}
		scanf("%d", &dest);
	    printf("Case %d:\n", kase);
       
        func();
        dijkstra(dest);
        for(int i = 0; i < n; i++)
        {
			if(dist[i] == inf) printf("Impossible\n");
			else printf("%d\n", dist[i]);
		}
		for(int i = 0; i < n; i++) v[i].clear();
	}
	return 0;
}
