#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'

vector<pair<ll,pair<ll,ll>>>v;
vector<pair<ll,ll>>tree[50005];
ll t, n, m, par[50005],siz[50005], lev[50005],parent[50005][31], mx[50005][31];
bool vis[50005];

ll f(ll u)
{
	if(par[u] == u) return u;
	return par[u] = f(par[u]);
}

void dsu(ll a, ll b)
{
	a = f(a);
	b = f(b);
	if(a!= b)
	{
		if(siz[a] < siz[b]) swap(a,b);
		par[b] = a;
		siz[a]+=siz[b];
	}
}

void MST()
{
	for(ll i = 1; i <= n; i++) {par[i] = i;siz[i] = 1;lev[i] = 0;}
	for(ll i = 0;i < m; i++)
	{
		ll a = v[i].second.first, b = v[i].second.second;
		ll d = f(a), e = f(b), c = v[i].first;
		if(d != e)
		{
			dsu(a,b);
			tree[a].push_back({b,c});
			tree[b].push_back({a,c});
		}
	}
}

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
				parent[u][k] = parent[temp][k-1];
			}
		}
	}	
}

void query(ll x, ll y)
{
	ll ans = 0;
	if(lev[x] != lev[y]) 
	{
		if(lev[x] > lev[y]) swap(x,y);
		for(ll k = 18; k >= 0; k--)
		{
			if((lev[y]- (1 << k)) >= lev[x])
			{
				ans = max(ans,mx[y][k]);
				if(k == 0) y = parent[y][0];
				else y = parent[y][k];
			}
		}
	}
	if(x == y)
	{
		printf("%lld\n",ans);
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
		       x = parent[x][up];
		       y = parent[y][up];
		   }
		   up--;
 	    }
 	     ans = max(ans, max(mx[x][0],mx[y][0]));
 	   //  x = parent[x][0];
 	    // y = parent[y][0];
 	     printf("%lld\n",ans);
	}
}
int main()
{	
	scanf("%lld",&t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld %lld",&n, &m);
		for(ll i = 1; i <= m; i++)
		{
			ll a, b, cost;
			scanf("%lld %lld %lld",&a, &b, &cost);
			v.push_back({cost,{a,b}});
		}
		sort(v.begin(),v.end());
		MST();
	
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
		v.clear();
		for(ll i = 1; i <= n; i++)
		{
			tree[i].clear();
		}
		memset(parent,0,sizeof(parent));
		memset(mx,0,sizeof(mx));
	} 
	return 0;
}
