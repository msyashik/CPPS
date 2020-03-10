#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 100005

//
ll dp[65][65];
int t;
char ch[105];

ll func(int i, int j)
{
	//cout << i  << " " << j << endl;
    if(i > j) return 0;
    if(i == j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    ll ans1 = 0,ans2 = 0;
    if(ch[i] == ch[j])
    {
		ans1 = 1 + func(i+1,j-1);
	}
	ans2 = func(i+1,j) + func(i,j-1) - func(i+1,j-1);
	return dp[i][j] = ans1 + ans2;
}

int main()
{	
	scanf("%d",&t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%s",ch);
		int n = strlen(ch);
		memset(dp,-1,sizeof(dp));
		ll ans = func(0,n-1);
		printf("Case %d: %lld\n",kase,ans);
	}
	return 0;
}
