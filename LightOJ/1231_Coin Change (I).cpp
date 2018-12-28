#include <bits/stdc++.h>

using namespace std;

#define mod 100000007

int n, k, m[55], coin[55], dp[55][1055];

int f(int i, int amount)
{
	if(i == n + 1) 
	{
		if(amount == k) return 1;
		else return 0;
	}
	
	if(dp[i][amount] != -1) return dp[i][amount];
	
	int ret1 = 0;
	
	for(int j = 1; j <= m[i]; j++)
	{
		if((amount+(coin[i]*j)) <= k)
		{
			ret1 += f(i+1, amount+(coin[i]*j)) % mod;
		}
		else break;
	}
	
	int ret2 = f(i+1, amount) % mod;
	
	return dp[i][amount] = (ret1 + ret2) % mod;
}



int main()
{
	
	int t;
	
	scanf("%d", &t);
	
	for(int kase = 1; kase <= t;kase++)
	{
		scanf("%d %d", &n, &k);
	    
	    memset(dp, -1, sizeof(dp));
	    	
		for(int i = 1; i <= n; i++) scanf("%d", &coin[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &m[i]);
		
		printf("Case %d: %d\n",kase, f(1,0));
		 
	}
	
	
	return 0;
}
