#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI acos(-1.0)

int main()
{
	ll t, a[100005], b[100005], c[100005];
	
	scanf("%lld", &t);
	for(int i = 1; i <= t; i++) scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
	for(int i = 2; i <= t; i++)
	{
		a[i] = a[i] + max(b[i-1],c[i-1]);
		b[i] = b[i] + max(a[i-1],c[i-1]);
		c[i] = c[i] + max(a[i-1],b[i-1]);
	}
	printf("%lld\n",max(a[t],max(b[t],c[t])));
	return 0;
}
