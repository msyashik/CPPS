#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int arr[] = {0,0,1,-1};
int brr[] = {1,-1,0,0};
int visited[110][110];
int t,n;
char ch[110][110];

void dfs(int i, int j)
{
	visited[i][j] = 1;
	
	for(int l = 0; l <= 3; l++)
	{
		int a = arr[l] + i;
		int b = brr[l] + j;
		if((a >= 1 && a <= n && b >= 1 && b <= n) && (ch[a][b] == 'x' || ch[a][b] == '@') && (visited[a][b] == 0))
		{
			dfs(a,b);
		}
	}
}

int main()
{	
	cin >> t;
	
	for(int kase = 1; kase <= t; kase++)
	{
		int coun = 0;
		memset(visited, 0, sizeof(visited));
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cin >> ch[i][j];
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(visited[i][j] == 0 && ch[i][j] == 'x')
				{
					coun++;
					dfs(i,j);
				}
			}
		}
		cout << "Case " << kase << ": " << coun << endl;
	}
	
	return 0;
}
