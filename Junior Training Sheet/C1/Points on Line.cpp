#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
	ll arr[100005],n,d;
	
	scanf("%lld %lld", &n,&d);
	for(ll i = 1; i <= n; i++) scanf("%lld",&arr[i]);
	ll ans = 0, prev = 1;
	for(ll i = 1; i<= n; i++)
	{
		while(arr[i]-arr[prev] > d) prev++;
		if(i-prev >= 2)
		{
			ans += (i-prev)*(i-prev-1)/2;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
