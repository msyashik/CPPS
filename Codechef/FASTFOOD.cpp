#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n";

int main()
{
	ll t, n, arr[100005], brr[100005], crr[100005], drr[100005];
	
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld", &n);
		
		ll summ = 0;
		
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &arr[i]);
			
			summ += arr[i];
			crr[i] = summ;
		}
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &brr[i]);
		}
		
		drr[n] = brr[n];
		
		for(int i = n-1; i >= 1; i--)
		{
			drr[i] = brr[i] + drr[i+1];
		}
		
		ll sum3 = 0, ans = 0;
		
		for(int i = 1; i <= n; i++)
		{
			if(i < n)
			{
			sum3 = crr[i] + drr[i+1];
		    }
			ans = max(sum3, ans);
		}
		
		ans = max(ans, max(drr[1], crr[n]));
		
		printf("%lld\n", ans);
		
	}
	
	return 0;
}
