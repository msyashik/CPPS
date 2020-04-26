#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define inf 100000000

int main()
{
	ll t, n, m;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld %lld", &n, &m);
		ll ans = m*(n/2);
		printf("Case %lld: %lld\n",kase,ans);
	}
	return 0;
}

//
