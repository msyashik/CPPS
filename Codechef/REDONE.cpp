//Problem link : https://www.codechef.com/MAY19B/problems/REDONE

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define mod 1000000007


ll dp[1000005];

void func()
{
	dp[1] = 1 % mod;
	dp[2] = 5 % mod;
	
	ll ans = 5%mod;
	
	for(ll i = 3; i <= 1000000; i++)
	{
		ans  = ((ans) + (i) + ((ans * i)));
		ans %= mod;
		
		dp[i] = ans;
	}
}


int main()
{
	func();
	
	Coming 
	
	ll t, n;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
	
		cout << dp[n] << endl;
	}
	
	
	return 0;
}
