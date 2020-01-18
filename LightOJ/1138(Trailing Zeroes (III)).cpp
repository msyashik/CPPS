#include <bits/stdc++.h>

using namespace std;
 
#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

ll coun = 0;
void func(ll n, ll p)
{
	coun = 0;
	while(n)
	{
        coun += (n/p);
        n /= p;		
	}
}

int main()
{
	//
	ll test, q;
	scanf("%lld", &test);
	for(ll kase = 1; kase <= test; kase++)
	{
		scanf("%lld", &q);
	    ll first = 1, last = 1000000000, mid = 0, mn = 0;
	    int f = 0;
	    while(first <= last)
	    {
			if(mn == q) {f = 1;break;}
		    else if(mn < q)
		    {
				first = mid+1;
			}
			else if(mn > q)
			{
				last = mid-1;
			}
			mid = (first+last) / 2;
	        func(mid,2);	
	        ll coun2 =  coun;
	        func(mid,5);
	        ll coun5 = coun;
	        mn = min(coun2, coun5);
	    }
	    if(f == 0) printf("Case %lld: impossible\n", kase);
	    else
	    {
			ll low = 1, hi = mid, md;
			ll ans = 0;
			ll ash = mid;
			while(low <= hi)
			{
				md = (hi+low)/2;
				func(md,2);
				ll coun22 = coun;
				func(md, 5);
				ll coun55 = coun;
				ans = min(coun22, coun55);
				if(ans == q) ash = min(ash, md);
				if(ans >= q) hi = md-1;
				else low = md+1;
			}
			printf("Case %lld: %lld\n", kase, ash);
		}
	}
	return 0;
}
