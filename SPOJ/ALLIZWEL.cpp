#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'

int t,r,c;
char ch[105][105];
int visited[105][105];

int arr[] = {-1,+1,0,0,+1,-1,+1,-1};
int brr[] = {0,0,-1,+1,+1,-1,-1,+1};
int f = 0;
char all[] = {'A','L','L','I','Z','Z','W','E','L','L'};	
	
bool yes(int ans, int ans2)
{
	if(ans >= 1 && ans <= r && ans2 >= 1 && ans2 <= c) return true;
	return false;
}	
	
void dfs(int p, int q, int coun)
{
	if(coun == 9)
	{
		f = 1;
		return;
	}
	for(int i = 0; i <= 7; i++)
	{
		if(f == 1) return;
		
		int ans = arr[i] + p;
		int ans2 = brr[i] + q;
		
		if(yes(ans,ans2) && visited[ans][ans2] == 0 && ch[ans][ans2] == all[coun+1])
		{
			visited[ans][ans2] = 1;
			dfs(ans,ans2,coun+1);
			visited[ans][ans2] = 0;
		}
	}
	return;
}	

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
	    scanf("%d %d", &r, &c);
	    getchar();
	    for(int i = 1;i <= r; i++)
	    {
			for(int j = 1;j <= c; j++)
			{
				scanf("%c",&ch[i][j]);
			}
			getchar();
		}
		 
	    memset(visited, 0, sizeof(visited));
	    
	    f = 0;
	    	
		for(int i = 1; i <= r; i++)
		{
			for(int j = 1; j <= c; j++)
			{
				if(f == 1) break;
				if(ch[i][j] == 'A' && visited[i][j] == 0)
				{
					dfs(i,j,0);
				}
			}
			if(f == 1) break;
		}

		if(f == 1) printf("YES\n");	
		else printf("NO\n");
	}
	return 0;
}
