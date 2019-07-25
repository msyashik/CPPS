#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	ll t,a,b,c;
	
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b >> c;
		cout << (a+b+c)/2 << endl;
	}
	
	return 0;
}
