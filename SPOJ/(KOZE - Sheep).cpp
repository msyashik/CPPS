#include <bits/stdc++.h>

using namespace std;

char ch[255][255];
int visited[255][255];
int arr[] = {0,0,-1,+1};
int brr[] = {-1,+1,0,0};
int sheep = 0, wolf = 0;
int n, m;

void dfs(int p, int q)
{
	if(ch[p][q] == 'k') sheep++;
	else if(ch[p][q] == 'v') wolf++;
	
	visited[p][q] = 1;
	
	for(int i = 0; i < 4; i++)
	{
		int ans1 = p + arr[i];
		int ans2 = q + brr[i];
		
		if(ans1 >= 1 && ans1 <= n && ans2 >= 1 && ans2 <= m && visited[ans1][ans2] == 0 && (ch[ans1][ans2] == 'v' || ch[ans1][ans2] == 'k' || ch[ans1][ans2] == '.'))
		{
			dfs(ans1,ans2);
		}
	}
}

int main()
{
	
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> ch[i][j];
		}
	}
	
	int first = 0, sec = 0;
	
    for(int i = 1; i <= n; i++)
    {
		for(int j = 1; j <= m; j++)
		{
			if((visited[i][j] == 0) && (ch[i][j] == 'k' || ch[i][j] == 'v'))
			{
				sheep = 0;
				wolf = 0;
				dfs(i,j);
				//cout << sheep << " " << wolf << endl;
				if(sheep > wolf)
				{
					sec += sheep;
				}
				else first += wolf;
			}
		}
	}	
	
	cout << sec << " " << first << endl;
	return 0;
}
