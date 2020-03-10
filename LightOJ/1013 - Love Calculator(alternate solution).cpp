#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 100005

char ch[35],bh[35];
int t,dp[35][35],len1,len2,len;
ll dp2[35][35][35];

int func(int i, int j)
{
	if(i >= len1 || j >= len2) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int ans = 0;
	if(ch[i] == bh[j])
	{
	    ans = 1 + func(i+1,j+1);	
	}
	else
	{
		ans = max(func(i,j+1),func(i+1,j));
	}
	return dp[i][j] = ans;
}	

ll ways(int i, int j, int currlen)
{
	if(i >= len1 || j >= len2)
	{
		if(i >= len1)
		{
			int anss = 0;
			anss = max(anss,len2-j);
			currlen+=anss;
			if(currlen==len) return 1;
			else return 0;
		}
		else
		{
			int anss = 0;
			anss = max(anss,len1-i);
			currlen += anss;
			if(currlen == len) return 1;
			else return 0;
		}
	}
	if(dp2[i][j][currlen] != -1) return dp2[i][j][currlen];
    ll ans = 0;
    if(ch[i] == bh[j])
    {
		ans = ways(i+1,j+1,currlen+1);
	}
	else
	{
		ans = ways(i+1,j,currlen+1) + ways(i,j+1,currlen+1);
	}
	return dp2[i][j][currlen] = ans;
}
int main()
{
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++)
    {
		scanf("%s %s",ch,bh);
		len1 = strlen(ch);
		len2 = strlen(bh);
		memset(dp,-1,sizeof(dp));
		int ans = func(0,0);
		len = (len1-ans)+(len2-ans)+ans;
		printf("Case %d: %d ",kase,(len1-ans)+(len2-ans)+ans);
		memset(dp2,-1,sizeof(dp2));
		ll ans2 = ways(0,0,0);
		printf("%lld\n",ans2);
	}	
	return 0;
}
