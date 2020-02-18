#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<pair<int,int>>v[10005], v2[10005];
int flag = 0, ash = INT_MAX, dist[10005][20];
int test, n, m, t, d;

void dijk(int node)
{
	priority_queue<pair<pair<int,int>, int>>pq;
	pq.push({{0,node}, 0});
	flag = 0;
	ash = INT_MAX;
	while(!pq.empty())
	{
		int top = pq.top().first.second;
		int cost = -1 * pq.top().first.first;
		int used = pq.top().second;
		pq.pop();
		if(top == n) 
		{
			flag = 1;
			ash = min(ash, cost);
			continue;
		}
		int len = v[top].size();
		for(int i = 0; i< len; i++)
		{
			int child = v[top][i].first;
			int man = v[top][i].second;
			int cur = (cost+man);
			if(cur < dist[child][used])
			{
				dist[child][used] = cur;
			    pq.push({{-1*cur, child}, used});
			}
		}
		int len2 = v2[top].size();
		for(int i = 0; i < len2; i++)
		{
			int child = v2[top][i].first;
			int man = v2[top][i].second;
			int use = used + 1;
			if(use>d) continue;
			else
			{
				int cur = (cost+man);
				if(cur < dist[child][use])
				{
					dist[child][use] = cur;
				    pq.push({{-1*cur,child}, use});
				}
			}
		}
	}
}

int main()
{	
	scanf("%d", &test);
	for(int kase = 1; kase <= test; kase++)
	{
		scanf("%d %d %d %d", &n,&m,&t,&d);
		n--;
		for(int i = 1; i <= m; i++)
		{
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			v[a].push_back({b,w});
		}
		for(int i = 1; i <= t; i++)
		{
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			v2[a].push_back({b,w});
		}
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= d; j++)
			{
				dist[i][j] = INT_MAX;
			}
		}
		dijk(0);
		printf("Case %d: ", kase);
		if(flag) printf("%d\n", ash);
		else printf("Impossible\n");
		for(int i = 0; i <= n; i++)
		{
			v[i].clear();
			v2[i].clear();
		}
	}
	return 0;
}
