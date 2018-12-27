#include <bits/stdc++.h>

using namespace std;

#define mod 100000007

int main()
{
	int t, n, k;
	int a[105], dp[10005];

	scanf("%d", &t);
	
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &n, &k);
		
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		
		memset(dp, 0, sizeof(dp));
		
		dp[0] = 1;
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = a[i]; j <= k; j++)
			{
				dp[j] = ((dp[j]%mod) + (dp[j - a[i]]%mod))%mod;
			}
		}
		
		printf("Case %d: %d\n", kase, dp[k]);
		
	}
	return 0;
}
