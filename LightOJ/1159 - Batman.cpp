#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 100005

int t;
char ch[55],bh[55],gh[55];
int dp[55][55][55], len1, len2, len3;

int func(int i, int j, int k)
{
	if(i >= len1 || j >= len2 || k >= len3) return 0;
	if(dp[i][j][k] != -1) return dp[i][j][k];
	int ans = 0;
	if(ch[i] == bh[j]  && bh[j] == gh[k])
	{
		ans = 1 + func(i+1,j+1,k+1);
	}
	else
	{
		int ans1 = func(i+1,j,k);
		int ans2 = func(i,j,k+1);
		int ans3 = func(i,j+1,k);
		int ans4 = func(i,j+1,k+1);
		int ans5 = func(i+1,j+1,k);
		int ans6 = func(i+1,j,k+1);
		ans = max(ans1,max(ans2, max(ans3, max(ans4,max(ans5,ans6)))));
	}
	return dp[i][j][k] = ans;
}

int main()
{	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%s %s %s",ch,bh,gh);
		len1 = strlen(ch), len2 = strlen(bh), len3 = strlen(gh);
		memset(dp,-1,sizeof(dp));
		int ans = func(0,0,0);
		printf("Case %d: %d\n",kase,ans);
	}
}
