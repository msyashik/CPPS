#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100005

int main()
{
	int t,n;
	ll a[2005];
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		ll coun = 0;
		sort(a+1,a+1+n);
		for(int i = n; i >= 3; i--)
		{
			int lo = 1; 
			int hi = i-1;
			while(lo < hi)
			{
				ll ans1 = a[lo]+a[hi];
				ll ans2 = a[i];
				if(ans1 > ans2)
				{
					coun += (hi-lo);
					hi--;
				}
				else lo++;
				
			}
		}
		printf("Case %d: %lld\n",kase,coun);
	}
}
