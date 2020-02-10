#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int t, n, m;
char ch[205][205];
vector<pair<int,int>>v;
int ans[205][205], ash[205][205];
bool vis[205][205];

int arr[] = {1,-1,0,0};
int brr[] = {0,0,-1,+1};

void bfs(int a, int b)
{
	queue<pair<int,int>>q;
	memset(vis,0,sizeof(vis));
	vis[a][b] = 1;
	q.push({a,b});
	ans[a][b] = 0;
	while(!q.empty())
	{
		int topa = q.front().first, topb = q.front().second;
		q.pop();
        for(int i = 0; i < 4; i++)
        {
			int aa = topa + arr[i];
			int bb = topb + brr[i];
			if(aa >= 1 && aa <= n && bb >= 1 && bb <= m && ch[aa][bb] != '#' && !vis[aa][bb])
			{
				vis[aa][bb] = 1;
				if(ans[topa][topb]+1 < ans[aa][bb])
				{
				    ans[aa][bb] = min(ans[aa][bb], ans[topa][topb] + 1);
				    q.push({aa,bb});
				}
			}
		}		
	}
}	

void bbfs(int a, int b)
{
	memset(vis,0,sizeof(vis));
	queue<pair<int,int>>q;
	q.push({a,b});
	vis[a][b] = 1;
	ash[a][b] = 0;
	int flag = 0,mn;
	if(a == 1 || a == n || b == 1 || b == m)
	{
		mn = 1;
		flag = 1;
		q.pop();
	}
	while(!q.empty())
	{
		int topa = q.front().first, topb = q.front().second;
		q.pop();
		if(flag) continue;
		for(int i = 0; i < 4; i++)
		{
			int aa = topa + arr[i];
			int bb = topb + brr[i];
			if(aa >= 1 && aa <= n && bb >= 1 && bb <= m && ch[aa][bb] != '#' && !vis[aa][bb])
			{
				int val = ash[topa][topb] + 1;
				if(val < ans[aa][bb])
				{
					vis[aa][bb] = 1;
					ash[aa][bb] = val;
					q.push({aa,bb});
					if(aa == 1 || aa == n || bb == 1  || bb == m)
		            {
			            flag = 1;
			            mn = val + 1;
		            }
				}
			}
		}
	}
	if(flag) printf("%d\n", mn);
	else printf("IMPOSSIBLE\n");
}

int main()
{	
	int j1,j2;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &n, &m);
		getchar();
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				scanf("%c", &ch[i][j]);
				if(ch[i][j] == 'J') {j1 = i;j2 = j;}
				if(ch[i][j] == 'F') v.push_back({i,j});
				if(ch[i][j] != '#') ans[i][j] = INT_MAX;
				if(ch[i][j] == '#') ans[i][j] = -1;
				ash[i][j] = 0;
			}
			getchar();
		}
		int len = v.size();
		for(int i = 0; i < len; i++)
		{
			int a = v[i].first;
			int b = v[i].second;
			bfs(a,b);
		}
		printf("Case %d: ", kase);
		bbfs(j1,j2);
		v.clear();
	}
}
