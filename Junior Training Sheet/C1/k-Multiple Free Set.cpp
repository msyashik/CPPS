#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll n,k, arr[100005];

void solve()
{
	cin >> n >> k;
	for(ll i =1 ; i <= n ;i++) cin >> arr[i];
	sort(arr+1,arr+n+1);
	set<ll>s;
	for(ll i = 1;i <= n;i++)
	{
		if(arr[i]%k) s.insert(arr[i]);
		else 
		{
			if(s.count(arr[i]/k)) continue;
			else s.insert(arr[i]);
		}
	}
	cout << s.size() << endl;
}

int main()
{
	solve();
}
