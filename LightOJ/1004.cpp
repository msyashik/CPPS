#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005

int main()
{
	int t, n;
	ll arr[11000];
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d", &n);
		int len = (n*(n+1))/2;
		for(int i = 1; i <= len; i++)
		{
			scanf("%lld", &arr[i]);
		}
		ll dp[11000];
		memset(dp,0,sizeof(dp));
		dp[1] = arr[1];
		int node = 1, inc = 1;
		for(int i =1 ;i <= n-1; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				int nodd = node + inc;
				dp[nodd] = max(dp[nodd], arr[nodd] + dp[node]);
				nodd++;
				dp[nodd] = max(dp[nodd], arr[nodd] + dp[node]);
				node++;
			}
			inc++;
		}
		/*for(int i = 1;i <= len; i++)
		{
			cout << dp[i] << endl;
		}*/
		int m = n-1;
		int baki = (m*(m+1))/2;
		for(int i = len+1; i <= (len+baki); i++)
		{
			scanf("%lld", &arr[i]);
		}
		int dec = n;
		node = len+1;
		for(int i = n-1; i >= 1; i--)
		{
			for(int j = 1; j <= i; j++)
			{
				dp[node] = max(dp[node], arr[node]+dp[node-dec]);
				dp[node] = max(dp[node], arr[node]+dp[(node-dec)+1]);
				node++;
			}
			dec--;
		}
		//cout << len << " " << baki << endl;
		int ashol = len+baki;
		printf("Case %d: %lld\n", kase, dp[ashol]);
	}
	return 0;
}
