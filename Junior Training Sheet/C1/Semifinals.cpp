//https://codeforces.com/contest/378/problem/B

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

ll n, a[100005], b[100005], ans1[100005], ans2[100005];

int main()
{
	cin >> n;
	for(ll i = 1;i <= n; i++) cin >> a[i] >> b[i];
	ll f = 1, s = 1, coun = 0;
	while(1)
	{
		if(coun == n) break;
		if(a[f] < b[s])
		{
			ans1[f] = 1;
			f++;
			coun++;
		}
		else if(b[s] < a[f])
		{
			ans2[s] = 1;
			s++;
			coun++;
		}
	}
	ll len =n/2;
	for(ll i = 1;i <= len; i++) {ans1[i] = 1; ans2[i] = 1;}
	for(ll i = 1;i <= n; i++)
	{
		if(ans1[i] == 1) cout << 1;
		else cout << 0;
	}
	cout << endl;
	for(ll i = 1;i <= n; i++)
	{
		if(ans2[i] == 1) cout << 1;
		else cout << 0;
	}
	cout << endl;
	
	return 0;
}
