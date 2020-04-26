#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define inf 100000000

int main()
{
	ll t;
	double v1,v2,v3,a1,a2;
	
	scanf("%lld",&t);
	for(ll kase =1; kase <= t; kase++)
	{
		scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
		double t1 = v1/a1;
		double t2 = v2/a2;
		double ti = max(t1,t2);
		double d1 = (v1*v1)/(2*a1);
		double d2 = (v2*v2)/(2*a2);
		double ans = ti*v3;
		printf("Case %lld: %lf %lf\n",kase,d1+d2,ans);
	}
	return 0;
}
