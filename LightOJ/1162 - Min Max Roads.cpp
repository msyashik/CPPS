#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'

vector<pair<ll,ll>>tree[100005];
ll t, n, m, lev[100005],parent[100005][20], mx[100005][20],mn[100005][20];
bool vis[100005];

void bfs(ll node)
{
	lev[node] = 0;
	queue<ll>q;
	q.push(node);
	vis[node] = 1;
	while(!q.empty())
	{
		ll top = q.front();
		ll len = tree[top].size();
		for(ll i = 0; i < len; i++)
		{
			ll child = tree[top][i].first;
			if(!vis[child])
			{
				vis[child] = 1;
				lev[child] = lev[top] + 1;
				parent[child][0] = top;
				q.push(child);
				mx[child][0] = tree[top][i].second;
				mn[child][0] = tree[top][i].second;
			}
		}
		q.pop();
	}
}

void init()
{
    for(ll k = 1; k <= 18; k++)
    {
		for(ll u = 1; u <= n; u++)
		{
			ll yes = lev[u] - (1 << k);
			if(yes >= 0)
			{
				ll temp = parent[u][k-1];
				mx[u][k] = max(mx[u][k-1], mx[temp][k-1]);
				mn[u][k] = min(mn[u][k-1], mn[temp][k-1]);
				parent[u][k] = parent[temp][k-1];
			}
		}
	}	
}

void query(ll x, ll y)
{
	ll ans = 0, ans2 = 10000000000000000;
	if(lev[x] != lev[y]) 
	{
		if(lev[x] > lev[y]) swap(x,y);
		for(ll k = 18; k >= 0; k--)
		{
			if((lev[y]- (1 << k)) >= lev[x])
			{
				ans = max(ans,mx[y][k]);
				ans2 = min(ans2,mn[y][k]);
				if(k == 0) y = parent[y][0];
				else y = parent[y][k];
			}
		}
	}
	if(x == y)
	{
		printf("%lld %lld\n",ans2, ans);
	}
	else
	{
	    ll up = 18;
	    while(up >= 0)
	    {
		   if(parent[x][up] != parent[y][up])
		   {
			   ans = max(ans,mx[x][up]);
		       ans = max(ans,mx[y][up]);
		       ans2 = min(ans2,min(mn[x][up],mn[y][up]));   
		       x = parent[x][up];
		       y = parent[y][up];
		   }
		   up--;
 	    }
 	     ans = max(ans, max(mx[x][0],mx[y][0]));
 	     ans2 = min(ans2,min(mn[x][0],mn[y][0]));
 	   //  x = parent[x][0];
 	    // y = parent[y][0];
 	     printf("%lld %lld\n",ans2, ans);
	}
}
int main()
{	
	scanf("%lld",&t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld",&n);
		m = n-1;
		for(ll i = 1; i <= m; i++)
		{
			ll a, b, cost;
			scanf("%lld %lld %lld",&a, &b, &cost);
			tree[a].push_back({b,cost});
			tree[b].push_back({a,cost});
		}
	
		ll indx;
		for(ll i = 1; i <= n; i++)
		{
			if(tree[i].size() == 1) 
			{
				indx = i;
				break;
			}
		}
		memset(vis,0,sizeof(vis));
		bfs(indx);
		init();
		
		ll q;
		printf("Case %lld:\n",kase);
		scanf("%lld",&q);
		for(ll i = 1; i <= q; i++)
		{
			ll x,y;
			scanf("%lld %lld",&x,&y);
			query(x,y);
		}
		for(ll i = 1; i <= n; i++)
		{
			tree[i].clear();
		}
		memset(parent,0,sizeof(parent));
		memset(mx,0,sizeof(mx));
	} 
	return 0;
}
