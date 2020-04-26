#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define inf 100000000

ll func(ll n)
{
	ll ans1 = n;
	ll ans2 = (2*1) + (n-1)*2;
	if(ans1%2 == 0) ans1 /= 2;
	else ans2 /= 2;
	return ans1*ans2;
}

int main()
{
	ll t, n;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld",&n);
		printf("Case %lld: ", kase);
		if(n == 1) {printf("1 1\n"); continue;}
		ll lo = 1, hi = 1e15,mid;
		bool yes = false;
		ll num;
		while(lo < hi)
		{
			if(yes) break;
			mid = (lo+hi)/2;
			ll ans = func(mid);
			if(n > ans) lo = mid + 1;
			else
			{
				ll ans2 = func(mid-1);
				if(n > ans2 && n <= ans)
				{
					num = mid;
					yes = true;
					break;
				}
				else
				{
					hi = mid;
				}
			}
		}
		ll ansf = func(num);
		ll anss = func(num-1);
		if(num%2)
		{
		    if(n <= (anss+num))
		    {
			    printf("%lld %lld\n",num,n-anss);
		    }
		    else
		    {
			    printf("%lld %lld\n",(ansf-n)+1,num);
		    }
		}
		else
		{
		    if(n <= (anss+num))
		    {
				printf("%lld %lld\n",n-anss,num);
			}
			else
			{
				printf("%lld %lld\n",num,(ansf-n)+1);
			}
		}
	}
	return 0;
}
//
