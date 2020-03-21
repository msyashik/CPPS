#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define mod 100000007

int t, n, k, s;
ll dp[2][15002];
ll prefix[2][15002];

int main()
{
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d %d", &n, &k, &s);
		memset(dp,0,sizeof(dp));
		memset(prefix,0,sizeof(prefix));
		
		prefix[1][0] = 0;
		for(int i = 1;i <= s; i++)
		{
			if(i <= k) dp[1][i] = 1;
			else dp[1][i] = 0;
			prefix[1][i] = ((dp[1][i]%mod) + (prefix[1][i-1]%mod))%mod;
		}
		for(int i = 2; i <= n; i++)
		{
			for(int j = 1; j <= s; j++)
			{
				int mx = max(0,j-k-1);
				dp[i%2][j] = ((prefix[(i-1)%2][j-1]%mod) - (prefix[(i-1)%2][mx]%mod) + mod)%mod;
				prefix[i%2][j] = ((dp[i%2][j]%mod) + (prefix[i%2][j-1]%mod))%mod;
			}
		}
		printf("Case %d: %lld\n",kase,dp[n%2][s]);
	}
	return 0;
}
