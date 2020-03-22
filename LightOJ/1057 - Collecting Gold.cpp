#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define mod 100000007
#define MAX 100000

int t, r, c;
char ch[25][25];
int R[25],C[25],gold,lim,dp[25][100000];

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

int func(int indx, int mask)
{
	if(mask == lim)
	{
		return max(abs( R[indx]- R[0]),abs(C[indx] - C[0]));
	}
	if(dp[indx][mask] != -1) return dp[indx][mask];
	int ans = 100000;
	for(int i = 1;i < gold; i++)
	{
		if(!checkbit(mask,i))
		{
			ans = min(ans, max(abs(R[indx]-R[i]),abs(C[indx]-C[i])) + func(i,setbit(mask,i)));
		}
	}
	return dp[indx][mask] = ans;
}

int main()
{
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		memset(dp,-1,sizeof(dp));
		gold = 1;
		scanf("%d %d", &r, &c);
		getchar();
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				scanf("%c",&ch[i][j]);
				if(ch[i][j] == 'x')
				{
					R[0] = i;
					C[0] = j;
				}
				else if(ch[i][j] == 'g')
				{
					R[gold] = i;
					C[gold] = j;
					gold++;
				}
			}
			getchar();
		}
		lim = (1 << gold) - 1;
		int ash = func(0,1);
		printf("Case %d: %d\n",kase,ash);
	}
	return 0;
}
