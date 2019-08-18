#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{	
	int t;
	ll n;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &n);
		int f = 1;
		for(ll i = 0; i <= 1000000; i++)
		{
			if(i*i > n)
			{
				f = 1;
				break;
			}
			ll baki = n - (i*i);
			ll sq = sqrt(baki);
			if(sq*sq == baki)
			{
				f = 0;
				break;
			}
		}
		if(f == 0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
