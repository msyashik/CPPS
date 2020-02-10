#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

ll t, n,m,sum = 0, arr[1005], vis[1005];
vector<ll>v[1005];	
ll val = 0,coun = 0;

void dfs(ll node)
{
	vis[node] = 1;
	coun++;
	val += arr[node];
	ll len = v[node].size();
	for(ll i = 0; i < len;i++)
	{
		ll child = v[node][i];
		if(!vis[child]) dfs(child);
	}
}
int main()
{
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld %lld", &n, &m);
		sum = 0;
		for(ll i = 1; i <= n; i++) 
		{
			scanf("%lld", &arr[i]);
			sum+=arr[i];
		}
		for(ll i = 1;i <= m; i++)
		{
			ll a, b;
			scanf("%lld %lld", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		ll div = sum/n;
		printf("Case %lld: ", kase);
		ll check = div*n;
		if(check != sum) printf("No\n");
		else
		{
			int flag = 0;
			for(ll i = 1; i <= n; i++)
			{
				if(flag) break;
				if(!vis[i]) 
				{
					val =0;
					coun = 0;
				    dfs(i);
				    ll avg = val/coun;
				    check = avg*coun;
				    if(check != val) flag = 1;
				    if(avg != div) 
				    {
						flag = 1;
					}
				}
			}
			if(flag) printf("No\n");
			else printf("Yes\n");
		}
		for(ll i = 1;i <= n; i++)
	    {
				v[i].clear();
				vis[i] = 0;
	    }
		
	}
	return 0;
}
