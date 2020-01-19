#include <bits/stdc++.h>

using namespace std;
 
#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

ll t, n, k, arr[1005];

bool func(ll p)
{
	ll total = 0, coun = 0;
	for(ll i = 1; i <= n+1; i++)
	{
		total += arr[i];
		if(total > p)
		{
			coun++;
			total = arr[i];
		}
	}
	if(coun <= k) return true;
	else return false;
}

int main()
{	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld %lld", &n, &k);
		ll sum = 0, fmx = 0;
		for(ll j = 1; j<= n+1; j++)
		{
			scanf("%lld", &arr[j]);
			sum += arr[j];
			fmx = max(fmx, arr[j]);
		}
		if(k == n)
		{
			printf("Case %lld: %lld\n", kase, fmx);
			for(ll i = 1; i <= n+1; i++) printf("%lld\n", arr[i]);
			continue;
		}
		else if(k == 0)
		{
			printf("Case %lld: %lld\n", kase, sum);
			printf("%lld\n", sum);
			continue;
		}
		ll low = 1, hi = sum, mid;
		ll mn = 1e10;
		while(low < hi)
		{
	        mid = (low+hi)/2;
	        bool ret = func(mid);
	        if(ret) 
	        {
				mn = min(mn,mid);
				hi = mid;
			}	
			else
			{
				low = mid + 1;
			}	
		}
		ll rest = 0, summ = 0, mx = 0;
		vector<ll>v;
		for(ll i = 1; i<= n+1; i++)
		{
			rest += arr[i];
			if(rest > mn)
			{
				summ+=(rest-arr[i]);
				mx = max(mx,rest-arr[i]);
				rest = arr[i];
			}
		}
		if(summ<sum) {mx = max(mx,sum-summ);}
		
		rest = 0, summ = 0;
		for(ll i = 1; i<= n+1; i++)
		{
			rest += arr[i];
			if(rest > mx)
			{
				summ+=(rest-arr[i]);
				mx = max(mx,rest-arr[i]);
				v.push_back(rest-arr[i]);
				rest = arr[i];
			}
		}
		if(summ < sum) v.push_back(sum-summ);
		
		
		
		printf("Case %lld: %lld\n", kase, mx);
		ll lens = v.size();
		vector<ll>vv;
		for(ll i = 0; i< lens;i++)
		{
		 if(v[i] > 0) vv.push_back(v[i]);
		}
		ll lenss = vv.size();
		if(lenss == k+1)
		{
		    for(ll i = 0;i < lenss; i++) 
		    {
			    printf("%lld\n", vv[i]);
		    }	
		}
		else
		{
		    ll baki,pos = -1, last = n+1;
		    for(ll i = lenss-1;i >= 0; i--) 
		    {
			    if(vv[i] > arr[last])
			    {
					ll dek= vv[i];
					vv[i] = vv[i] - arr[last];
					baki = dek - vv[i];
					pos = i;
					break;
				}
				last--;
		    }
		    for(ll i = 0; i < lenss; i++) 
		    {
				if(pos == i)
				{
					printf("%lld\n%lld\n",vv[i],baki);
				}
				else printf("%lld\n",vv[i]);
			}
		}
	}
	return 0;
}
