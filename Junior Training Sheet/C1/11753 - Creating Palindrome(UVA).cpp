#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll t, n,k, arr[10005];

ll func(ll f, ll s, ll total)
{
	if(total > k) return total;
	if(f >= s) return total;
	int ans1 = 100000, ans2 = 100000, ans3 = 100000;
	if(arr[f] == arr[s])
	{
		ans1 = func(f+1,s-1,total);
	}
	else
	{
		ans2 = func(f+1,s,total+1);
		ans3 = func(f,s-1,total+1);
	}
	return min(ans1,min(ans2,ans3));
}

int main()
{	
	scanf("%lld",&t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld %lld",&n,&k);
		for(ll i = 1; i <= n; i++)
		{
			scanf("%lld",&arr[i]);
		}
		ll ans = func(1,n,0);
		printf("Case %lld: ",kase);
		if(ans == 0) printf("Too easy\n");
		else if(ans > k) printf("Too difficult\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
