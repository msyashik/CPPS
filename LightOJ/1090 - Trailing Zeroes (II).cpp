#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define eps 1e-9

ll twos[1000005], fives[1000005], ans, ans2;

void func()
{
	for(ll i = 1; i <= 1000000; i++)
	{
		ll x = i, y = i;
		ll total = 0;
		while(x)
		{
			total += x/2;
			x/=2;
		}
		twos[i] = total;
		ll total2 = 0;
		while(y)
		{
			total2 += y/5;
			y/=5;
		}
		fives[i] = total2;
	}
}

void func2(ll i)
{
    ll x = i,y = i, total = 0, total2 = 0;
	while(x%2 == 0)
	{
		x/=2;
		total++;
	}
	while(y%5 == 0)
	{
		y/=5;
		total2++;
	}
	ans = total;
	ans2 = total2;
}
int main()
{
	func();	
	
	ll t, n, r, p, q;
	
	scanf("%lld", &t);
	for(ll kase = 1 ;kase <= t; kase++)
	{
		scanf("%lld %lld %lld %lld", &n, &r, &p, &q);
		ll nr = n-r;
		ll tw = twos[n] - (twos[r] + twos[nr]);
		ll fv = fives[n] - (fives[r] + fives[nr]);
		func2(p);
		ll tws = ans*q;
		ll fvs = ans2*q;
		tw += tws;
		fv += fvs;
		ll anss = min(tw,fv);
		printf("Case %lld: %lld\n", kase, anss);
	}
	return 0;
}
