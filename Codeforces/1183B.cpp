//Problem Link : https://codeforces.com/problemset/problem/1183/B

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	
	int q,n,k,a;
	
	cin >> q;
	
	while(q--)
	{
		cin >> n >> k;
		
		int mn = INT_MAX, mx = -1*INT_MAX;;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> a;
			
			if(a < mn) mn = a;
			if(a > mx) mx = a;
		}
		
		ll ans1 = k+mx;
		ll ans2 = k+mn;
		
		ll mxx = max(ans1,ans2);
		ll minn = min(ans1,ans2);
		
		if(abs(mxx - mx) <= k && abs(mxx - mn) <= k)
		{
			cout << mxx << endl;
		}
		else if(abs(minn - mx) <= k && abs(minn - mn) <= k)
		{
			cout << minn << endl;
		}
		else cout << -1 << endl;
	}
	
	return 0;
}
