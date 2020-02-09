#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
vector<int>v[1005];
bool vis[1005];
int coun[1005], per, ans = 0; 
int t,n, m, arr[1005];
 
void bfs(int node)
{
	memset(vis,0,sizeof(vis));
	vis[node] = 1;
	coun[node]++;
	queue<int>q;
	q.push(node);
	while(!q.empty())
	{
		int top = q.front();
		q.pop();
		if(coun[top] == per) ans++;
		int len = v[top].size();
		for(int i = 0; i < len; i++)
		{
			int child = v[top][i];
			if(!vis[child])
		    { 
			    vis[child] = 1;
			    coun[child]++;
			    q.push(child);
		    }
		}
	}
} 

int main()
{	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d %d", &per, &n, &m);
		for(int i = 1; i <= per; i++) scanf("%d", &arr[i]);
		for(int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d %d",&a, &b);
			v[a].push_back(b);
		}
		ans = 0;
		for(int i = 1; i <= per; i++)
		{
			bfs(arr[i]);
		}
		printf("Case %d: %d\n", kase, ans);
		for(int i = 1;i <=n; i++)
		{
			v[i].clear();
			coun[i] = 0;
		}
	}
	return 0;
}
