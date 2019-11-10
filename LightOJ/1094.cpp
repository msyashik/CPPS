#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100005

bool vis[30005];
vector<pair<int,int>>v[30005];
ll key,mx = INT_MIN;

void dfs(int node,ll sum)
{
	vis[node] =1 ;
	if(sum > mx)
	{
		mx = sum;
		key = node;
	}
	int len = v[node].size();
	for(int i = 0; i < len; i++)
	{
		int child = v[node][i].first;
		int ww = v[node][i].second;
		if(!vis[child]) dfs(child,sum+ww);
	}
	return;
}

int main()
{
	int q,n,a,b,w;
	
	scanf("%d",&q);
	for(int kase = 1; kase <= q; kase++)
	{
		scanf("%d",&n);
		n--;
		for(int i = 1 ;i <= n; i++)
		{
			scanf("%d %d %d",&a,&b,&w);
			v[a].push_back({b,w});
			v[b].push_back({a,w});
		}
		mx = 0;
		memset(vis,0,sizeof(vis));
		dfs(0,0);
		mx = 0;
		memset(vis,0,sizeof(vis));
		dfs(key,0);
		printf("Case %d: %lld\n",kase,mx);
		for(int i = 0; i <= n; i++) v[i].clear();
	}
	return 0;
}
