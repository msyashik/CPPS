#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define eps 1e-9

bool leapyear(ll n)
{
	if(n%400 == 0) return true;
	if((n%4) == 0 && (n%100) != 0) return true;
	return false;
}

int main()
{		
	ll t, da, y, da2,y2;
	string ch, bh;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		cin >> ch;
		scanf("%lld,%lld",&da,&y);
		cin >> bh;
		scanf("%lld,%lld",&da2,&y2);
		
		ll x = y-1;
		ll ans = (x/4) - (x/100) + (x/400);
		ll ans2 = (y2/4) - (y2/100) + (y2/400);
		ll total = ans2-ans;
		if(leapyear(y))
		{
			if(!(ch == "January" || ch == "February")) total--;
		}
		if(leapyear(y2))
		{
			if(bh == "January") total--;
			else if(bh == "February")
			{
				if(da2 != 29) total--;
			}
		}
		printf("Case %lld: %lld\n",kase,total);
	}
	return 0;
}
