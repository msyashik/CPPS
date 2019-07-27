#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,q, arr[205],d,m,coun = 0;
int dp[205][205][205];

int KnapSack(int i, int j, int sum)
{
	if(j == m && sum == 0) return 1;
	if(j == m && sum != 0) return 0;
	if(i == n) return 0;
	
	if(dp[i][j][sum] != -1) return dp[i][j][sum];
	return dp[i][j][sum] = KnapSack(i+1,j,sum%d) + KnapSack(i+1,j+1,(sum+arr[i])%d);
}

int main()
{
	int set = 1;
	while(scanf("%d %d", &n, &q) == 2)
	{
		if(n == 0 && q == 0) return 0;
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i]; 
		}
		cout << "SET " << set << ":\n";
		set++;
		int query = 1;
		for(int i = 1; i <= q; i++)
		{
		    memset(dp, -1, sizeof(dp));
			cin >> d >> m;
			int ans = KnapSack(0,0,0);
			cout << "QUERY " << query << ": "<< ans<< endl;
		    query++;
		}
	}
	
	return 0;
}
