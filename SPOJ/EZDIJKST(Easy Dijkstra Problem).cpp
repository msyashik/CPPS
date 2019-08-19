#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<ll>v[10005];
ll cost[10005][10005];
priority_queue<pair<ll,ll>>pq;
ll distt[10005];
//int path[10005];

void dij(int node)
{
	distt[node] = 0;
	pq.push({0,node});
    
    while(!pq.empty())
    {
		ll top = pq.top().second;
		int len = v[top].size();
		pq.pop();
		
		for(int i = 0; i < len; i++)
		{
			ll nodd = v[top][i];
			if(distt[top]+cost[top][nodd] <= distt[nodd])
			{
				distt[nodd] = distt[top] + cost[top][nodd];
				pq.push({distt[nodd], nodd});
			}
		}
	}	
}

int main()
{
	int t,start,end;
	scanf("%d", &t);
	while(t--)
	{
	int d, n, e, a,b;
	
	scanf("%d %d", &n , &e);
	
	for(int i = 1; i <= n; i++)
	{
		distt[i] = INT_MAX;
		v[i].clear();
	}
	
	for(int i = 1; i <= e; i++)
	{
		scanf("%d %d %d", &a, &b, &d);
		cost[a][b] = d;
		v[a].push_back(b);
		//v[b].push_back(a);
	}
	
	scanf("%d %d", &start, &end);
	dij(start);
	
	if(distt[end] == INT_MAX) printf("NO\n");
	else printf("%lld\n",distt[end]);
	
    }
	return 0;
}
