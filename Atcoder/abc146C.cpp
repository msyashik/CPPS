#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100005
 
int func(ll n)
{
	int coun = 0;
	while(n)
	{
		n /= 10;
		coun++;
	}
	return coun;
} 
int main()
{
	
	//cout << func(100);
	
	ll a,b,x;
	
	cin >> a >> b >> x;
	int f = 1;
	int l = 1e9;
	ll man = 0;
	int mid = (f+l)/2;
	while(1)
	{
		if(f>l) break;
	    ll ans = (a*mid) + (b*func(mid));
	    if(ans > x)
	    {
			l = mid-1;
			mid = (f+l)/2;
		}
		else 
		{
			f = mid + 1;
			mid = (f+l)/2;
			man = max(man,ans);
		}
	}
	
	cout << mid << endl;
	
	return 0;
}
