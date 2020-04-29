#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 10000005

ll ans[5000005];
char sieve[SIZE];

void calcu()
{
    sieve[0] = 1,sieve[1] = 1;
    sieve[2] = 0;
    for(ll i = 2; i <= 5000000; i++) ans[i] = i;
    for(ll i = 2; i <= 5000000; i++)
    {
		if(sieve[i] == 0)
		{
			for(ll j = i; j <= 5000000; j+=i)
			{
				sieve[j] = 1;
				ans[j] /= i;
				ans[j]*= (i-1);
			}
		}
	}
	for(ll i = 3;i <= 5000000; i++)
	{
		ans[i] *= ans[i];
		ans[i] += ans[i-1];
	}
}

int main()
{
	calcu();
	
	ll t, a, b;
	
	scanf("%llu", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%llu %llu", &a, &b);
		ll ash = ans[b] - ans[a-1];
		printf("Case %llu: %llu\n",kase,ash);
	}
	return 0;
}
