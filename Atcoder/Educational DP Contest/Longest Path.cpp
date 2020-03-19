#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100005

vector<int>v[100005];
bool vis[100005];
int dp[100005];

int func(int node)
{
	vis[node] = 1;
	int len = v[node].size();
	int ans = 0;
	
	for(int i = 0;i <len ;i++)
	{
		int child = v[node][i];
		if(!vis[child])
		{
			int curr = 1 + func(child);
			ans = max(ans,curr);
		}
		else
		{
			ans = max(ans,1+dp[child]);
		}
	}
	return dp[node] = ans;
}

int main()
{
	int n,m;
	
	scanf("%d %d", &n, &m);
	for(int i =1 ;i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}
	int mx = 0;
	for(int i =1 ; i <= n; i++)
	{
		if(!vis[i])
		{
			int ans = func(i);
			mx = max(mx,ans);
		}
	}
	printf("%d\n",mx);
	return 0;
}
