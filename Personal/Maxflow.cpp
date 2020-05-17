//Maxflow(undirected graph)
//Devskill(Shajib)

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LIM 500
#define INF 100000008

ll n,m,G[LIM][LIM]; /// src: 1, des: n
ll vis[LIM],mx[LIM],par[LIM];

ll bfs()
{
	memset(vis,0,sizeof(vis));
	vis[1] = 1;
	mx[1] = INF;
	queue<ll>q;
	q.push(1);
	while(!q.empty())
	{
		ll u = q.front();q.pop();
		for(ll v = 1; v <= n; v++)
		{
			if(!G[u][v] || vis[v]) continue;
			vis[v] = 1;
			mx[v] = min(mx[u],G[u][v]);
			par[v] = u;
			q.push(v);
		}
	}
	if(vis[n] == 0) return 0;
	
	ll v = n, u = par[n];
	while(v != 1)
	{
		cout << v << " "; // printing path
		G[u][v] -= mx[n];
		G[v][u] += mx[n];
		u = par[u];
		v = par[v];
	}
	cout << 1 << endl;
	return mx[n];
}

ll flow()
{
	ll ans = 0;
	while(true)
	{
		ll curr = bfs();
		ans+=curr;
		cout << curr << endl; // flow which is passed using using the path
		if(!curr) break; /// if curr is zero then break
	}
	return ans;
}

int main()
{
	ll T;
	scanf("%lld", &T);
	for(ll t = 1; t <= T; t++)
	{
		scanf("%lld %lld", &n,&m);
		memset(G,0,sizeof(G)); ///capacity graph
		for(ll i = 0; i < m;i++)
		{
			ll u,v,c;
			scanf("%lld %lld %lld",&u,&v,&c);
		    G[u][v] += c;
		}
		printf("%lld\n",flow());
	}
	return 0;
}
/**
 1
 6 7
 1 2 2
 1 3 5
 2 5 1
 2 4 3
 3 4 3
 5 6 4
 4 6 4
 **/
