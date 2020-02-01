#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

ll arr[200005], n, q, a, b, c, par[200005], val[200005];

ll find_par(ll indx, ll cost)
{
	ll total = val[indx] + cost;
	if(total > arr[indx])
	{
		ll rest = cost - (arr[indx] - val[indx]);
		val[indx] = arr[indx];
		if(par[indx] == indx) return indx;
		return par[indx] = find_par(par[indx], rest);
	}
	else
	{
		val[indx] = total;
		return indx;
	}
}

int main()
{
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
		if(i!=n) par[i] = i+1;
		else par[i] = i;
	}
	
	scanf("%lld", &q);
	while(q--)
	{
		scanf("%lld", &a);
		if(a == 1)
		{
			scanf("%lld %lld",&b, &c);
			ll node = find_par(b,c);
			//par[b] = node;
		}
		else
		{
			scanf("%lld", &b);
			printf("%lld\n", val[b]);
		}
	}
	return 0;
}
