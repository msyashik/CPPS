#include <bits/stdc++.h>

using namespace std;

int n, CAP, arr[2005],cost[2005];
int dp[2005][2005];

int knapsack(int i, int val)
{
	//base case
	if(i == n+1)
	{
		return 0;
	}
	
	// visited
	
	if(dp[i][val] != -1) return dp[i][val];
	
	//unvisited
	
	int ans1 = 0, ans2 = 0;
	
	if(val+arr[i] <= CAP)
	{
		ans1 = cost[i] + knapsack(i+1, val+arr[i]);
	}
	ans2 = knapsack(i+1, val);
	
	return dp[i][val] = max(ans1,ans2);
}

int main()
{
	scanf("%d %d", &CAP, &n);
	
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &arr[i], &cost[i]);
	}
	
	memset(dp,-1,sizeof(dp));
	
	int ans = knapsack(1,0);
	
	printf("%d\n",ans);
	
	return 0;
}
