#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define endl '\n'

double func(double x, double y, double z, double p, double q, double r)
{
	double val = sqrt((fabs(x-p)*fabs(x-p)) + (fabs(y-q)*fabs(y-q)) + (fabs(z-r)*fabs(z-r)));
	return val;
}

int main()
{
	//IOS;
	int t;
	double x1, y1, z1, x2, y2 , z2, x, y, z;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2, &x, &y, &z);
		double lowx = x1, lowy = y1, lowz = z1, hix = x2, hiy = y2, hiz = z2, mid1x, mid1y, mid1z, mid2x, mid2y, mid2z;
		double ans = INT_MAX*1.0;
		//int mx = 50;
		while(1)
		{
			double f1 = func(lowx, lowy, lowz, hix, hiy, hiz);
			if(f1 <= 1e-9) break;
			
		    mid1x = lowx + (hix-lowx)/3;
		    mid1y = lowy + (hiy-lowy)/3;
		    mid1z = lowz + (hiz-lowz)/3;
		    
		    mid2x = hix - (hix-lowx)/3;
		    mid2y = hiy - (hiy-lowy)/3;
		    mid2z = hiz - (hiz-lowz)/3;
		    
		    double dis1 = func(x,y, z, mid1x, mid1y, mid1z);
		    double dis2 = func(x,y, z, mid2x, mid2y, mid2z);
		    if(dis1 > dis2)
		    {
			    lowx = mid1x;
			    lowy = mid1y;
			    lowz = mid1z;
			    ans = min(ans, dis2);	
			}	
			else if(dis2 > dis1)
			{
				hix = mid2x;
				hiy = mid2y;
				hiz = mid2z;
				ans = min(ans, dis1);
			}
			else
			{
				lowx = mid1x;
				lowy = mid1y;
				lowz = mid1z;
				hix =  mid2x;
				hiy =  mid2y;
				hiz =  mid2z;
				ans = min(ans, dis1);
			}
			//cout  << ans << endl;
			//cout << lowx << " " << lowy << " " << lowz << " " << hix << " " << hiy << " " << hiz << endl;
			//if(lowx ==  hix && lowy == hiy && lowz == hiz) cout << "YES\n";
		}
		printf("Case %d: %.10lf\n",kase, ans);
	}
	
	return 0;
}
