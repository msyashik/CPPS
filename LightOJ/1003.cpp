#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define endl '\n'

vector<int>v[10005];
bool vis[10005], col[100005];
int flag = 0;

void dfs(int node)
{
	if(flag) return;
	vis[node] = 1;
	int len = v[node].size();
	for(int i = 0; i < len ; i++)
	{
		int child =  v[node][i];
		if(!vis[child]) dfs(child);
		else if(vis[child] && col[child] == 0) 
		{
			flag = 1;
			return;
		}
	}
	col[node] = 1;
}
int main()
{
	int t, n;
	map<string,int>m;
	string ch,bh;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d", &n);
		int coun = 0;
		while(n--)
		{
			cin >> ch >> bh;
			if(m.count(ch) == 0)
			{
				coun++;
				m.insert({ch,coun});
			}
			if(m.count(bh) == 0)
			{
				coun++;
				m.insert({bh,coun});
			}
			int a = m[ch];
			int b = m[bh];
			v[a].push_back(b);
		}
		flag = 0;
		for(int i = 1; i <= coun; i++)
		{
			if(flag) break;
			if(!vis[i]) dfs(i);
		}
		printf("Case %d: ", kase);
		if(flag) printf("No\n");
		else printf("Yes\n");
		for(int i = 1; i <= coun; i++)
		{
			vis[i] = 0;
			col[i] = 0;
			v[i].clear();
		}
		m.clear();
	}
	return 0;
}
