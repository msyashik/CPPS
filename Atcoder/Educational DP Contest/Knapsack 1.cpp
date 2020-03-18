#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI acos(-1.0)

ll dp[110][105005];
int n, w, weight[105], cost[105];

ll func(int indx, int curr)
{
    if(indx > n) return 0;
    if(dp[indx][curr] != -1) return dp[indx][curr];
    ll ans1 = 0, ans2 = 0;
    if(curr+weight[indx] <= w)
    {
		ans1 = cost[indx] + func(indx+1,curr+weight[indx]);
	}	
	ans2 = func(indx+1,curr);
	return dp[indx][curr] = max(ans1,ans2);
}

int main()
{	
	scanf("%d %d", &n, &w);
	for(int i =1 ; i <= n; i++) scanf("%d %d", &weight[i],&cost[i]);
	memset(dp,-1,sizeof(dp));
	ll ans = func(1,0);
	printf("%lld\n",ans);
	
	return 0;
}
