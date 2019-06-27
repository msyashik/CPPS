//Problem Link: https://atcoder.jp/contests/abc118/tasks/abc118_c

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	Coming 
	
	ll n,a;
	ll sum = 0;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		sum = __gcd(a,sum);
	}
	
	cout << sum << endl;
	
	return 0;
}
