#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define MX 150005
#define endl '\n'
#define mod 100000007

int main()
{	
	int t,n,r[25],g[25],b[25];
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d %d %d", &r[i],&g[i],&b[i]);
		for(int i =2 ; i <= n; i++)
		{
			r[i] = r[i] + min(g[i-1],b[i-1]);
			g[i] = g[i] + min(r[i-1],b[i-1]);
			b[i] = b[i] + min(r[i-1],g[i-1]);
		}
		int ans = min(r[n],min(g[n],b[n]));
        printf("Case %d: %d\n",kase, ans);
	}
	return 0;
}
