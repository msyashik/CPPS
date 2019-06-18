//Problem link : https://www.codechef.com/problems/FAPF

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n";

int main()
{
	Coming 
	
	ll t, n, q, arr[200005], a, b;
	
	cin >> t;
	
	while(t--)
	{
		vector<ll>v;
		
		cin >> n >> q;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			v.push_back(arr[i]);
		}
		
		sort(v.begin(), v.end());
		
		for(int i = 1; i <= q; i++)
		{
			cin >> a >> b;
			
		    ll sum = abs(arr[a] -arr[b]) + b-a;
		    ll len1 = upper_bound(v.begin(), v.end(), max(arr[a], arr[b])) - v.begin();
		    ll len2 = lower_bound(v.begin(), v.end(), min(arr[a], arr[b])) - v.begin();
		    
		    ll lenn = len1 - len2;
		    
		    cout << sum << " " << lenn << endl;
		}
		
		v.clear();
	}
	return 0;
}
