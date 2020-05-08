// Problem Link : https://codeforces.com/contest/296/problem/C

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

ll n, m, k, arr[100005], a[100005], b[100005], val[100005], query[100005], ans[100005];

int main()
{	
	cin >> n >> m >> k;
	for(ll i = 1; i <= n; i++) cin >> arr[i];
	for(ll i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i] >> val[i];
	}
	ll f, s;
	for(ll i = 1; i<= k; i++)
	{
		cin >> f >> s;
		query[f]++;
		query[s+1]--;
	}
	for(ll i = 2; i <= m; i++)
	{
		query[i] = query[i] + query[i-1];
	}
	for(ll i = 1;i <= m; i++)
	{
		ll curr = val[i]*query[i];
		ans[a[i]] += curr;
		ans[b[i]+1] -= curr;
	}
	for(ll i = 2; i<= n; i++)
	{
		ans[i] = ans[i] + ans[i-1];
	}
	for(ll i = 1; i <= n; i++)
	{
		cout << ans[i]+arr[i] << " ";
	}
	cout << endl;
	return 0;
}
