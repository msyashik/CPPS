#include <bits/stdc++.h>

using namespace std;

#define int long long  
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 10000005

int32_t main()
{
	double a,b,c;
	
    while(scanf("%lf %lf %lf",&a,&b,&c) == 3)
    {
		double ans1 = (a/(a+b))*(b/(a+b-c-1));
		double ans2 = (b/(a+b))*((b-1)/(a+b-c-1));
		printf("%.5lf\n",ans1+ans2);
	}
	return 0;
}
