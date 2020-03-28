#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'

vector<ll>v[100005];
ll lev[100005],arr[100005],par[100005][31],coun;
ll t, n, q;

void init()
{
	for(ll k = 1; k <= 18; k++)
	{
		for(ll u = 1; u <= coun ;u++)
		{
			ll dest = (1 << k);
			if(lev[u]-dest < 0) continue;
			par[u][k] = par[par[u][k-1]][k-1];
		}
	}
}

void query(ll node, ll val)
{
	ll up = 18;
	while(up >= 0)
	{
		int yes = lev[node]-(1<<up);
		if(yes >= 0 && arr[par[node][up]] >= val)
		{
			node = par[node][up];
		}
		up--;
	}
	printf("%lld\n",node);
}

int main()
{    
    scanf("%lld",&t);
    for(ll kase = 1; kase <= t; kase++)
    {
	    scanf("%lld %lld", &n,&q);
	    n--;
	    lev[0] = 0, coun = 0,arr[0] = 1;
	    for(ll i = 1; i <= n;i++)
	    {
			ll node, val;
			scanf("%lld %lld",&node,&val);
			coun++;
			v[node].push_back(coun);
			arr[coun] = val;
			par[coun][0] = node;
			lev[coun] = lev[node] + 1;
		}
		init();	
		printf("Case %lld:\n",kase);
		while(q--)
		{
			ll node, val;
			scanf("%lld %lld",&node,&val);
			query(node,val);
		}
		for(ll i = 1; i <= n; i++)
		{
			v[i].clear();
			lev[i] = 0;
		}
	}
    	
	return 0;
}
