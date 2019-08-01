#include <bits/stdc++.h>

using namespace std;

queue<pair<int,int>>q;
int r1,r2,c1,c2;
int visited[10][10];
int level[10][10];
int arr[] = {0,0,2,-2};
int brr[] = {2,-2,0,0};

void bfs(int i, int j)
{
    q.push({i,j});
    visited[i][j] = 1;
    level[i][j] = 0;
    
    while(!q.empty())
    {
		int top_row = q.front().first;
		int top_col = q.front().second;
		
		q.pop();
		
		//cout << top_row << " " << top_col << endl;
		
		if(top_row == r2 && top_col == c2)
		{
			cout << level[top_row][top_col] << endl;
			break;
		}
		
        for(int i = 0; i < 4; i++)
        {
			int ans1 = top_row + arr[i];
			int ans2 = top_col + brr[i];
			if(arr[i] == 0)
			{
				int f = ans1 + 1;
				int s = ans1 - 1;
				
				if(f >= 1 && f <= 8 && ans2 >= 1 && ans2 <= 8 && visited[f][ans2] == 0)
				{
					visited[f][ans2] = 1;
					q.push({f,ans2});
					level[f][ans2] = level[top_row][top_col] + 1;
				}
				if(s >= 1 && s <= 8 && ans2 >= 1 && ans2 <= 8 && visited[s][ans2] == 0)
				{
					visited[s][ans2] = 1;
					q.push({s,ans2});
					level[s][ans2] = level[top_row][top_col] + 1;
				}
			}
			else
			{
				int f = ans2 + 1;
				int s = ans2 - 1;
				
				if(f >= 1 && f <= 8 && ans1 >= 1 && ans1 <= 8 && visited[ans1][f] == 0)
				{
					visited[ans1][f] = 1;
					q.push({ans1,f});
					level[ans1][f] = level[top_row][top_col] + 1;
				}
				if( s >= 1 && s <= 8 && ans1 >= 1 && ans1 <= 8 && visited[ans1][s] == 0)
				{
					visited[ans1][s] = 1;
					q.push({ans1,s});
					level[ans1][s] = level[top_row][top_col] + 1;
				}
			}
		}		
	}
	
	while(!q.empty())
	{
		q.pop();
	}
}

int main()
{
	int t;
	string ch,gh;
	
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		cin >> ch >> gh;
		
		r1 = ch[0] - 'a' + 1;
		c1 = ch[1] - '0';
		r2 = gh[0] - 'a' + 1;
		c2 = gh[1] - '0';
		
		memset(visited, 0, sizeof(visited));
		memset(level, 0, sizeof(level));
		
		bfs(r1,c1);
	}
	return 0;
}
