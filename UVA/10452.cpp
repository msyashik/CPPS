#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int arr[] = {0,0,-1};
int brr[] = {-1,1,0};
int t, n, m,pos1,pos2;
char ch[10][10];
int visited[10][10];
int f = 0;

void dfs(int i, int j)
{
	visited[i][j] = 1;
	
	for(int l = 0; l <= 2; l++)
	{
		if(f == 1) return;
		int ans1 = arr[l] + i;
		int ans2 = brr[l] + j;
		
		if(ans1 >= 1 && ans1 <= n && ans2 >= 1 && ans2 <= m && (ch[ans1][ans2] == '#' || ch[ans1][ans2] == 'I' || ch[ans1][ans2] == 'E' || ch[ans1][ans2] == 'H' || ch[ans1][ans2] == 'O' || ch[ans1][ans2] == 'V' || ch[ans1][ans2] == 'A') && visited[ans1][ans2] == 0)
		{
			if((i-ans1) == 1 && (j-ans2) == 0)
			{
				if(ch[ans1][ans2] == '#') {
					cout << "forth";
					f=1;return;
			    }
				cout << "forth ";
			}
			else if((i-ans1) == 0 && (j-ans2) == 1)
			{
				if(ch[ans1][ans2] == '#') {
					cout << "left";
					f=1;return;
			    }
				cout << "left ";
			}

			else 
			{
				if(ch[ans1][ans2] == '#') {
					cout << "right";
					f=1;return;
			    }
			cout << "right ";
			}
		    dfs(ans1, ans2);	
		}
		//else if(ans1 >= 1 && ans1 <= n && ans2 >= 1 && ans2 <= m && ch[ans1][ans2] == '#') return; 
	}
}

int main()
{	
	cin >> t;
	while(t--)
	{
		memset(visited, 0, sizeof(visited));
		f=0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
			    cin >> ch[i][j];
			    if(ch[i][j] == '@') 
			    {
					pos1 = i;
					pos2 = j;
				}	
			}
		}
		
		dfs(pos1, pos2);
		cout << endl;
	}
	return 0;
}
