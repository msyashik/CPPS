#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int arr[] = {1,-1,0,0};
int brr[] = {0,0,-1,+1};
int t, n, m;
char ch[25][25];
bool vis[25][25];

void bfs(int a, int b)
{
	vis[a][b] = 1;
	queue<pair<int,int>>q;
	q.push({a,b});
	int total = 1;
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
				q.push({aa,bb});
				vis[aa][bb] = 1;
				total++;
			}
		}
	}
	printf("%d\n",total);
}

int main()
{	
	scanf("%d", &t);
	for(int kase =1; kase <= t; kase++)
	{
		scanf("%d %d", &m, &n);
		getchar();
		int pos1,pos2;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				scanf("%c", &ch[i][j]);
				if(ch[i][j] == '@') {pos1 = i;pos2 = j;} 
				vis[i][j] = 0;
			}
			getchar();
		}
		printf("Case %d: ", kase);
		bfs(pos1,pos2);
		
	}
	return 0;
}
