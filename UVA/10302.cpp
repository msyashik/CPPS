#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int main()
{
	//Coming 
	
	ll n;
	
	while(scanf("%lld", &n) == 1)
	{
		ll ans =  (n*(n+1)) / 2;
		
		cout << ans*ans << endl;	
	}
	
	return 0;
}
