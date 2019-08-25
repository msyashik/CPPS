#include <bits/stdc++.h>

using namespace std;

int coin[] = {1,5,10,25,50};
int dp[10000][10000];
int n;

int coin_change(int i, int amount)
{
	if(i == 5 || amount == 0) 
	{
		if(amount == 0) return 1;
		else return 0;
	}
	
	if(dp[i][amount] != -1) return dp[i][amount];
	
	int ans1 = 0, ans2 = 0;
	
	if(amount-coin[i] >= 0) 
	{
	    ans1 = coin_change(i, amount-coin[i]);
	}
	ans2 = coin_change(i+1, amount);
	
	return dp[i][amount] = ans1 + ans2;
}

int main()
{	
	memset(dp, -1, sizeof(dp));
	
	while(scanf("%d", &n) == 1)
	{
	    int ans = coin_change(0,n);
	    cout << ans << endl;	
	}
	
	return 0;
}
