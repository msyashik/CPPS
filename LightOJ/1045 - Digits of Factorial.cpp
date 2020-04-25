#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 1005
#define eps 1e-9

double arr[1000005];

void func()
{
	double sum = 0;
	for(ll i = 1; i <= 1000000; i++)
	{
		sum += log10(i);
		arr[i] = sum;
	}
}

int main()
{
	func();
	ll t, n, base;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld %lld", &n, &base);
		printf("Case %lld: ", kase);	
		ll ans = (arr[n]/log10(base)) + 1 + eps;
		printf("%lld\n", ans);
	}
	return 0;
}
//
