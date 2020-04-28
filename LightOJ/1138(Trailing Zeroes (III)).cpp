#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define eps 1e-9

ll func(ll n)
{
	ll twos = 0, x = n;
	while(x)
	{
		twos += x/2;
		x/= 2;
	}
	ll fives = 0;
	while(n)
	{
		fives += n/5;
		n/=5;
	}
	//cout << twos << " " << fives << endl;
	return min(twos,fives);
}

int main()
{	
	ll t, n;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
	    scanf("%lld", &n);
	    printf("Case %lld: ", kase);
	    ll mid, lo = 1, hi = 1000000000, val = 1e16;
	    bool yes = false;
	    while(lo < hi)
	    {
			mid = (lo + hi) / 2;
			ll ans = func(mid);
			if(ans == n) 
			{
				yes = true;
				hi = mid;
				val = min(val,mid);
			}
			else if(ans < n) lo = mid + 1;
			else if(ans > n) hi = mid;
		}
		if(yes) printf("%lld\n",val);
		else printf("impossible\n");	
	}
	
	return 0;
}
