#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100000005

ll sz,p;

void solve()
{
    ll li = sz, col = sz;
    ll sq = sqrt(p);
    if(sq*sq == p && sq&1)
    {
		ll rest = (sz-sq)/2;
		printf("Line = %lld, column = %lld.\n",sz-rest,sz-rest);
	}	
	else
	{
		ll lo;
		if(sq%2) lo = sq;
		else lo = sq-1;
		//cout<< lo << " "<< hi << endl;
		ll loline = sz - (sz-lo)/2;
		ll locol = sz - (sz-lo)/2;
		//cout << loline << " "<< locol << endl;
		loline = loline+1;
		ll curr = lo*lo + 1;
		if(curr == p)
		{
			printf("Line = %lld, column = %lld.\n",loline,locol);
			return;
		}
		ll baki = lo;///
		if(p <= (curr+baki))
		{
			locol = locol - (p - curr);
			printf("Line = %lld, column = %lld.\n",loline,locol);
			return;
		}
		locol = locol - ((curr+baki)- curr);
		//cout<< loline << " "<< locol << endl;
		loline-=1;
		curr+=baki+1;
        if(p <= (curr+baki))
		{
			loline = loline - (p - curr);
			printf("Line = %lld, column = %lld.\n",loline,locol);
			return;
		}
		loline = loline - ((curr+baki)-curr);
		locol+=1;
		curr+=baki+1;
		//cout << loline << " "<< locol << " "<< curr << endl;
		if(p <= (curr+baki))
		{
			locol = locol + (p - curr);
			printf("Line = %lld, column = %lld.\n",loline,locol);
			return;
		}
		locol = locol + ((curr+baki)- curr);
		loline+=1;
		curr+=baki+1;
		//cout << loline << " "<< locol << " "<< curr << endl;
		if(p <= (curr+baki))
		{
			loline = loline + (p - curr);
			printf("Line = %lld, column = %lld.\n",loline,locol);
			return;
		}
	}
}
int main()
{	
	while(scanf("%lld %lld",&sz,&p) == 2)
	{
		if(sz == 0 && p == 0) return 0;
		solve();
	}
	return 0;
}
