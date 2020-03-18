#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI acos(-1.0)

ll dp[100105];
int n, k,arr[100005];

ll func(int indx)
{
	if(indx == n) return 0;
	if(dp[indx] != -1) return dp[indx];
	int len = min(indx+k, n);
	ll total = INT_MAX;
	for(int i = indx+1; i <= len;i++)
	{
		ll ans = abs(arr[indx]-arr[i]) + func(i);
		total = min(total,ans);
	}
	return dp[indx] = total;
}

int main()
{   
    scanf("%d %d", &n, &k);
    for(int i = 1;i <= n; i++)
    {
		scanf("%d", &arr[i]);
	}
	memset(dp,-1,sizeof(dp));
	ll ans = func(1);
	printf("%lld\n",ans);
	    	
	return 0;
}
