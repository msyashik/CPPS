#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define inf 100000000

int main()
{
	ll t,a,b,c,d;
	char ch[1005];
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
	    scanf("%s",ch);
	    printf("Case %lld: ",kase);
	    string aa = "",bb = "",cc = "",dd = "";
	    ll len = strlen(ch);
	    ll coun = 1;
	    for(ll i = 0; i < len; i++)
	    {
			if(ch[i] == '.')
			{
				coun++;
			}
			else
			{
				if(coun == 1) aa += ch[i];
				else if(coun == 2) bb += ch[i];
				else if(coun ==3) cc += ch[i];
				else dd += ch[i];
			}
		}
		ll sum1 = 0, po = 1;
		for(ll i = 7; i >= 0; i--)
		{
			sum1 = sum1 + ((aa[i] - '0') * po);
			po*=2;
		}
		if(sum1!=a)
		{
			printf("No\n");
			continue;
		}
		po = 1;
		ll sum2 = 0;
		for(ll i = 7; i >= 0; i--)
		{
			sum2 = sum2 + ((bb[i] - '0') * po);
			po*=2;
		}
		if(sum2!=b)
		{
			printf("No\n");
			continue;
		}
		po = 1;
		ll sum3 = 0;
		for(ll i = 7; i >= 0; i--)
		{
			sum3 = sum3 + ((cc[i] - '0') * po);
			po*=2;
		}
		if(sum3!=c)
		{
			printf("No\n");
			continue;
		}
		po = 1;
		ll sum4 = 0;
		for(ll i = 7; i >= 0; i--)
		{
			sum4 = sum4 + ((dd[i] - '0') * po);
			po*=2;
		}
		if(sum4!=d)
		{
			printf("No\n");
			continue;
		}
		else
		{
			cout << "Yes\n";
		}
	}
	return 0;
}
