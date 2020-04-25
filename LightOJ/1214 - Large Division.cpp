#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define inf 100000000

int main()
{
	ll t, b;
    char ch[1005];
	
	scanf("%lld", &t);
	for(ll kase = 1 ;kase <= t; kase++)
	{
		scanf("%s %lld",ch,&b);
		printf("Case %lld: ", kase);
		b = abs(b);
		ll start = 0;
		if(ch[0] == '-') start = 1;
		ll len = strlen(ch)-1;
		ll sum = 0;
		for(ll i = start; i <= len; i++)
		{	
			sum = (sum * 10) + (ch[i] - '0');
			if(sum >= b) sum = sum%b;
		}
		if(sum == 0) printf("divisible\n");
		else printf("not divisible\n");
	}
	return 0;
}
