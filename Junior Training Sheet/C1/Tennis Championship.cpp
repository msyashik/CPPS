#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
	ll n;
	
	cin >>n;
	if(n == 2) cout << 1 << endl;
	else if(n == 3) cout << 2 << endl;
	else
	{
		ll a = 2, b = 3,tot, ans = 2;
		while(1)
		{
			tot = a + b;
			if(tot > n) break;
			a = b;
			b = tot;
			ans++;
		}
		cout << ans<<endl;
	}
	
}

int main()
{
	solve();
	return 0;
}
