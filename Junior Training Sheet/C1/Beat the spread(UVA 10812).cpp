#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

int main()
{
	ll t, a, b;
	
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld %lld", &a, &b);
		if(a == 0 && b == 0) printf("0 0\n");
		else if(a < b) printf("impossible\n");
		else
		{
			ll mx = (a+b)/2;
			ll mn = a - mx;
			if(mx+mn == a && mx-mn == b) printf("%lld %lld\n", mx, mn);
			else printf("impossible\n");
		}
	}
	return 0;
}
