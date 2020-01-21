#include <bits/stdc++.h>

using namespace std;
 
#define ll long long int
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define val 1e18

ll arr[35];
vector<ll>v, vta, vtb;
int f = 0;
ll a1[33000],b1[33000];

void func(int indx, int last)
{
	if(indx >= last) 
	{
		ll sum = 0;
		for(int i = 0; i < (int)v.size(); i++) sum += v[i];
     	if(f == 0) vta.push_back(sum);
		else vtb.push_back(sum);
	    return;
	}
	func(indx+1, last);
	v.push_back(arr[indx]);
	func(indx+1, last);
	if(v.size()>0) v.erase(v.begin()+v.size()-1);
}

int main()
{
   ll t, n, w;
   scanf("%lld", &t);
   for(ll kase = 1; kase  <= t; kase++)
   {
	   scanf("%lld %lld", &n, &w);
	   for(ll i = 0; i< n; i++) scanf("%lld", &arr[i]);
	   ll ta = n>>1;
	   f = 0;
	   func(0,ta);
	   ll len1 = vta.size();
	   for(ll i = 0; i < len1; i++) a1[i] = vta[i];
	   f = 1;
	   func(ta,n);
	   ll len2 = vtb.size();
	   for(ll i = 0; i < len2; i++) b1[i] = vtb[i];
	   
	   sort(b1,b1+len2);
	   
	  ll sum = 0;
	   for(ll i = 0; i < len1; i++)
	   {
		   ll rest = w-a1[i];
		   if(rest>=0)
		   {
			   ll man = upper_bound(b1, b1+len2,rest)-b1;
			   sum += man;
		   }
	   }
	   printf("Case %lld: %lld\n", kase, sum);
	   vta.clear();
	   vtb.clear();
   }
}
