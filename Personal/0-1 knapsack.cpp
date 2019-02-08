// 0-1 knapsack
// recursive dp

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000 // give your desired value

int weight[MAX];
int cost[MAX];
int dp[MAX][MAX];
int parent[MAX];
int CAP, n;

int knap(int i, int unit)
{
	if(i >= n)
	{
		return 0;
	}
	
	int ans1 = 0, ans2 = 0;
	
	ans1 = knap(i+1, unit);
	
	if((unit + weight[i]) <= CAP) ans2 = knap(i+1, unit + weight[i]) + cost[i];
	else ans2 = 0;
    
    if(ans1 < ans2) parent[ans2] = i; // saving the path
    	
	return max(ans1, ans2);
}

int main()
{

        memset(dp, -1, sizeof(dp));
	memset(parent, -1, sizeof(parent));
	
	int n;
	
	cin >> n >> CAP;
	
	for(int i = 0; i < n; i++)
	{
		cin >> weight[i] >> cost[i];
		
	}
	
	int ans = knap(0, 0);
	
	
	cout << ans << "\n"; // max profit 
    	
        int coin;
    	
        while(ans > 0) // the items which was selected 
        {	
	    coin = parent[ans];
	    
	    cout << cost[coin] << " ";
	    
	    ans = ans - cost[coin];	
	} 	
    	
	return 0;
}
