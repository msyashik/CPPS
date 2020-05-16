#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int main()
{
	ll a;
	
	cin >> a ;
	
	if(a == 1 || a == 2) {cout << -1 << endl;return 0;}
	
	if(a%2 == 0)
	{
		ll b = ((a/2)*(a/2)) - 1;
		
		cout << b << " " << b+2 << endl;
	}
	else
	{
		ll b = (a*a - 1)/2;
		
		cout << b << " "<< b+1 << endl;
	}
	
    return 0;	
}
