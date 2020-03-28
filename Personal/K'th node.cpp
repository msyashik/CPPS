void init()
{
	for(ll k = 1; k <= 18; k++)
	{
		for(ll u = 1; u <= coun ;u++) // node = number of nodes in the graph
		{
			ll dest = (1 << k);
			if(lev[u]-dest < 0) continue;
			par[u][k] = par[par[u][k-1]][k-1];
		}
	}
}

void query(ll node, ll k)
{
	ll up = 18;
	ll l = lev[node] - k;
	while(up >= 0)
	{
		int yes = lev[node]-(1<<up);
		if(yes >= 0 && lev[par[node][up]] >= l)
		{
			node = par[node][up];
		}
		up--;
	}
	printf("%lld\n",node);
}
