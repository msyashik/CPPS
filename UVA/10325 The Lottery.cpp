#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

ll n, m, arr[100005];
stack<ll>q;
ll total = 0;

void func(ll indx)
{
	if(indx > m)
	{
		if(q.size() == 0) return;
		stack<ll>qq = q;
		ll lcm = qq.top();
		qq.pop();
		while(!qq.empty())
		{
			ll top = qq.top();
			lcm = (top*lcm)/(__gcd(lcm,top));
			qq.pop();
		}
		if(q.size()%2) total += (n/lcm);
		else total -= (n/lcm);
		return;
	}
	func(indx+1);
	q.push(arr[indx]);
	func(indx+1);
	q.pop();
}

int main()
{	
	while(scanf("%lld %lld",&n,&m) == 2)
	{
		total = 0;
		for(ll i = 1; i <= m; i++)
		{
			scanf("%lld",&arr[i]);
		}
		func(1);
		printf("%lld\n",n - total);
	}
	return 0;
}
