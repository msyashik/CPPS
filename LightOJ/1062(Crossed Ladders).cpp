#include <bits/stdc++.h>

using namespace std;
 
#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define val 1e-8

double x,y,c,mid;

double func(double w)
{
	return 1-(c/sqrt(x*x-w*w))-(c/sqrt(y*y-w*w));
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%lf %lf %lf", &x, &y, &c);
		double low = 0, hi = min(x,y);
		
		while(hi-low > val)
		{
			mid = (low+hi)/2;
			if(func(mid) > 0) 
			{
				low = mid;
			}
			else hi = mid;
		}
		printf("Case %d: %lf\n", kase, mid);
	}
	return 0;
}
