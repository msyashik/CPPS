#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100005

int rest;
double dp[3050][1550];
bool vis[3550][1550];
int t;
double arr[3005];

double func(int indx, int taken)
{
	if(indx > t) return 1.0;
	if(vis[indx][taken]) return dp[indx][taken];
	vis[indx][taken] = 1;
	double ans1 = 0;
	if(taken-1 >= 0)
	{
		ans1 = (1 - arr[indx]) * func(indx+1,taken-1);
	}
	double ans2 = arr[indx] * func(indx+1,taken);
	return dp[indx][taken] = ans1 + ans2;
}

int main()
{   
    scanf("%d", &t);
    for(int i =1 ;i <= t; i++)
    {
		scanf("%lf",&arr[i]);
	}
	rest = t/2;	
	double ans = func(1,rest);
	printf("%0.10lf\n",ans);
	
	return 0;
}
