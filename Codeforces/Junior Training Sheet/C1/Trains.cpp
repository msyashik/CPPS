//Problem Link: https://codeforces.com/contest/88/problem/C

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0).cout.tie(0);

int main()
{
	ll a, b;
	
	cin >> a >> b;
	ll lcm = (a*b)/__gcd(a,b);
	ll ans1 = (lcm-1)/a;
	ll ans2 = (lcm-1)/b;
	if(ans1 < ans2)ans1++;
	else ans2++;
	
	if(ans1 > ans2) cout<< "Dasha\n";
	else if(ans2 > ans1) cout <<"Masha\n";
	else cout << "Equal\n";
	return 0;
}
