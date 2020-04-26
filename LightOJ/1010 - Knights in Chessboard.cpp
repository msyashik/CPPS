#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define inf 100000000

int main()
{
	ll t,r,c;
	
	scanf("%lld",&t);
	for(ll kase =1; kase <= t; kase++)
	{
		scanf("%lld %lld",&r,&c);
		ll ans = ((r*c)+1)/2;
		if(r == 1 || c == 1) 
		{
		    ans = r*c;
		    printf("Case %lld: %lld\n",kase,ans);
		}
		else if(r == 2 || c == 2){
            ll big = max(r, c);
            ans = big;
            if(big % 4 == 1 || big % 4 == 3) ans++;
            if(big % 4 == 2 ) ans+=2;
            printf("Case %lld: %lld\n",kase,ans);
        }
        else
        {
		    printf("Case %lld: %lld\n",kase,ans);
		}
	}
	return 0;
}
