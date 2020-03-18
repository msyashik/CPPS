#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI acos(-1.0)
#define mod 1000000007

ll dp[1005][1005];
int r, c;
char ch[1005][1005];
	
ll func(int i,int j)
{
	if(i == r && j == c) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	int r1 = i+1, c1 = j;
	ll ans1 = 0, ans2 = 0;
	if(r1 >= 1 && r1 <= r && c1 >= 1 && c1 <= c && ch[r1][c1] == '.')
	{
		ans1 = func(r1,c1);
	}
	int r2 = i, c2 =  j+1;
	if(r2 >= 1 && r2 <= r && c2 >= 1 && c2 <= c && ch[r2][c2] == '.')
	{
		ans2 = func(r2,c2);
	}
    return dp[i][j] = ((ans1%mod) + (ans2%mod))%mod;
}

int main()
{	
	scanf("%d %d", &r, &c);
	getchar();
	for(int i =1 ;i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			scanf("%c",&ch[i][j]);
		}
		getchar();
	}
	memset(dp,-1,sizeof(dp));
	ll ans = func(1,1);
	printf("%lld\n",ans);
	return 0;
}
