#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define mod 100
#define MAXN 100000

int t, n, arr[20][20], dp[20][1<<17];

int setbit(int num, int x)
{
	int mask = num | (1 << x);
	return mask;
}
int checkbit(int num, int x)
{
	int mask = num & (1 << x);
	return mask;
}
int func(int indx, int num)
{
	if(indx > n) return 0;
	if(dp[indx][num] != -1) return dp[indx][num];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!checkbit(num,i))
		{
			ans = max(ans,arr[indx][i] + func(indx+1, setbit(num,i)));
		}
	}
	return dp[indx][num] = ans;
}

int main()
{	
	scanf("%d",&t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d", &n);
		memset(dp,-1,sizeof(dp));
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		int ans = func(1,0);
		printf("Case %d: %d\n",kase,ans);
	}
	return 0;
}
