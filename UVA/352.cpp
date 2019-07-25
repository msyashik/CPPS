#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int arr[] = {-1,1,1,-1,0,0,-1,1};
int brr[] = {1,-1,1,-1,-1,1,0,0};
int visited[105][105];
int t;
char ch[105][105];
	
void dfs(int i, int j)
{
	visited[i][j] = 1;
	
	for(int l = 0; l <= 7; l++)
	{
		int ans = arr[l] + i;
		int ans2 = brr[l] + j;
		
		if(ans >= 1 && ans <= t && ans2 >= 1 && ans2 <= t && ch[ans][ans2] == '1' && visited[ans][ans2] == 0)
		{
			dfs(ans, ans2);
		}
	}
}

int main()
{	
	int kase = 1;
	while(scanf("%d",&t) == 1)
	{
	
	memset(visited, 0, sizeof(visited));
	
	for(int i = 1; i <= t; i++)
	{
		for(int j = 1; j <= t; j++)
		{
			cin >> ch[i][j];
		}
	}
		
	int coun = 0;
	
	for(int i = 1; i <= t; i++)
	{
		for(int j = 1; j <= t; j++)
		{
			if(ch[i][j] == '1' && visited[i][j] == 0) 
			{
				coun++;
				dfs(i,j);
			}
		}
	}
	cout << "Image number " << kase << " contains " << coun << " war eagles.\n";
    kase++;
    }
	return 0;
}
