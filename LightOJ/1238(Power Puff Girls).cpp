#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int t, n, m, a1, a2, b1,b2, c1,c2, h, ans[25][25],vis[25][25],h1,h2;
char ch[25][25];
int arr[] = {0,0,1,-1};
int brr[] = {-1,+1,0,0};

void bfs(int p, int q)
{
	queue<pair<int,int>>s;
	s.push({p,q});
	ans[p][q] = 0;
	vis[p][q] = 1;
	
	while(!s.empty())
	{
		int topa = s.front().first, topb = s.front().second;
		s.pop();
		if(ch[topa][topb] == 'h') continue;
		for(int i = 0; i < 4; i++)
		{
			int aa1 = topa+arr[i];
			int aa2 = topb+brr[i];
			if(aa1 >= 1 && aa1 <= n && aa2 >= 1 && aa2 <= m && ch[aa1][aa2]!='#'&&ch[aa1][aa2]!='m' && !vis[aa1][aa2])
			{
				vis[aa1][aa2] = 1;
				s.push({aa1,aa2});
				ans[aa1][aa2] = ans[topa][topb] + 1;
			}
		}
	}
}

int main()
{

	scanf("%d", &t);
    for(int kase =1 ; kase <= t; kase++)
    {
		scanf("%d %d", &n, &m);
		getchar();
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				scanf("%c", &ch[i][j]);
				if(ch[i][j] == 'a')
				{
					a1 = i;
					a2 = j;
				}
				if(ch[i][j] == 'b')
				{
					b1 = i;
					b2 = j;
				}
				if(ch[i][j] == 'c')
				{
					c1 = i;
					c2 = j;
				}
				if(ch[i][j] == 'h')
				{
					h1 = i;
					h2 = j;
				}
				
				
			}
			getchar();
		}
		int mx = 0;
		bfs(a1,a2);
		mx = max(mx,ans[h1][h2]);
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		bfs(b1,b2);
		mx = max(mx,ans[h1][h2]);
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		bfs(c1,c2);
		mx = max(mx,ans[h1][h2]);
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		printf("Case %d: %d\n", kase, mx);
	}
	return 0;
}
