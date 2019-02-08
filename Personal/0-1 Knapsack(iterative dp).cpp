// 0-1 knapsack
// iterative dp

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000 // give your desired value

int weight[MAX];
int cost[MAX];
int dp[MAX][MAX];
int CAP, n;

int main()
{	
	int n;
	
	cin >> n >> CAP;
	
	for(int i = 0; i < n; i++)
	{
		cin >> weight[i] >> cost[i];
		
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= CAP; j++)
		{
			if(j == 0) dp[i][j] = 0;
			else if(i == 0) 
			{
				if(j >= weight[i]) dp[i][j] = cost[i];
				else dp[i][j] = 0;
			}
			else
			{
				if(j < weight[i]) dp[i][j] = dp[i-1][j];
				
				else dp[i][j] = max(cost[i] + dp[i-1][j - weight[i]], dp[i-1][j]);
			}
		}
	}
	
    cout << dp[n-1][CAP] << "\n";
    
    int cap = CAP;
    int m = n - 1;
    
    while(cap > 0) 
    {
		if(dp[m][cap] == dp[m-1][cap])
		{
			m = m - 1;
		}
		else
		{
			cout << cost[m] << " ";
			
			cap = cap - weight[m];
			m = m -1;
		}
	}
    	
	return 0;
}
