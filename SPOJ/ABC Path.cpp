#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define endl '\n'

int r, c,ans,kase = 1;
char ch[55][55];
int mx = 0;
int arr[] = {0,0,1,-1,-1,+1,-1,+1}; 
int brr[] = {-1,+1,0,0,-1,+1,+1,-1};
int visited[55][55];

void dfs(int r1, int c1, int coun)
{
	 visited[r1][c1] = 1;
	 mx = max(mx,coun+1);
     
     for(int i = 0; i <= 7; i++)
     {
		 int ans1 = r1 + arr[i];
		 int ans2 = c1 + brr[i];
		 
		 if(ans1 >= 1 && ans1 <= r && ans2 >= 1 && ans2 <= c && visited[ans1][ans2] == 0 && (ch[r1][c1]+1 == ch[ans1][ans2]))
		 {
			 dfs(ans1, ans2, coun+1);
		 }
	 }
	 return;	
}


int main()
{
	while(scanf("%d %d", &r, &c) == 2)
	{
		getchar();
		if(r == 0 && c == 0)  return 0;
	    for(int i = 1; i <= r; i++)
	    {
		    for(int j = 1; j <= c; j++)
		    {
			    scanf("%c", &ch[i][j]);
		    }
		    getchar();
	    }
	    
	    mx = 0;
	    memset(visited, 0, sizeof(visited));
	    
        for(int i = 1; i <= r; i++)
        {
			for(int j = 1; j <= c; j++)
			{
				if(visited[i][j] == 0 && ch[i][j] == 'A')
				{
					dfs(i,j,0);
				}
			}
		}	    
	    
	   printf("Case %d: %d\n", kase, mx);
	   kase++;
	}
	return 0;
}
