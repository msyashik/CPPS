#include <bits/stdc++.h>

using namespace std;
 
#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

ll t, n,k, arr[10005], coun = 0;

bool func(ll p)
{
	coun = 0;
	ll f = 0, total = 0;
	for(int i = 1; i<=n; i++)
	{
		total += arr[i];
		f = 1;
		if(total == p)
		{
			coun++;
			total = 0;
			f = 0;
		}
		else if(total > p)
		{
			coun++;
			total = arr[i];
		}
	}
	if(f == 1) 
	{
		coun++;
		f = 0;
		total = 0;
	}
	if(coun == k) return true;
	else return false;
}

int main()
{	
	scanf("%lld", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%lld %lld", &n , &k);
		ll sum = 0;
		bool same = true;
		ll mxx = 0;
		for(int i= 1; i <= n; i++)
		{
			scanf("%lld", &arr[i]);
			sum += arr[i];
			mxx = max(arr[i], mxx);
			if(i >= 2)
			{
				if(arr[i] != arr[i-1]) same = false;
			}
		}
		ll ash = 0;
		ll total = 0;
		if(k == 1) ash = sum;
		else if(k > n) ash = mxx;
		else
		{
		ll low = 1, hi = sum, mid;
		ll ans = 1e10;
		while(low <= hi)
		{
			mid = (low+hi)/2;
			bool ret = func(mid);
			if(ret)
			{
				hi = mid-1;
				ans = min(ans, mid);
			}
			else if(coun > k)
			{
				low = mid+1;
			}
			else  hi = mid-1;
		}
		if(ans == 1e10)
		{
			
			if(same) ash =  arr[1]+arr[2];
			else ash = arr[1];
		}
		else
		{
		ash = 0;
		
		for(int i = 1;i <= n; i++)
		{
			total += arr[i];
			if(total == ans)
			{
				ash = max(ash,total);
				total = 0;
			}
			else if(total > ans)
			{
				ash = max(ash, total-arr[i]);
				total = arr[i];
			}
		}
	    }
		ash = max(ash, total);
	    }
		printf("Case %d: %lld\n",kase, ash);
	}
	return 0;
}
