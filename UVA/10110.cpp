#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	ll a;
	
	while(1)
	{
		cin >> a;
		if(a == 0) return 0; 
		ll ans = sqrt(a);
		if((ans*ans) == a) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
