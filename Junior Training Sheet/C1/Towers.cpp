//Problem Link: https://codeforces.com/contest/479/problem/B

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

ll n, m, arr[105], posmx, posmn, mx = 0, mn = 1e5;
vector<pair<ll,ll>>v;

int main()
{
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) 
	{
	    cin >> arr[i];
	    if(arr[i] > mx)
	    {
			mx = arr[i];
			posmx = i;
		}
		if(arr[i] < mn)
		{
			mn = arr[i];
			posmn = i;
		}
	}
	ll coun = 0;
	while(coun < m)
	{
	    ll rm = mx-1;
	    ll rn = mn+1;
	    if(rn > rm) break;
	    v.push_back({posmx,posmn});
	    arr[posmn] += 1; arr[posmx] -=1;
	    
	    coun++; mx = 0, mn = 1e5;
	    
	    for(ll i = 1; i <= n; i++) 
	    {
	        if(arr[i] > mx)
	        {
			    mx = arr[i];
			    posmx = i;
		    }
		    if(arr[i] < mn)
		    {
			    mn = arr[i];
			    posmn = i;
		    }
	    }	
	}
	cout << mx-mn << " " << coun << endl;
	for(auto it:v)
	{
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}
