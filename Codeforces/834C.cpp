#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define endl "\n"

int main()
{
	Fastest
	
    ll t,a,b;
	
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b;
		
	    ll ans = cbrt(a*b);
	    
	    if((ans*ans*ans) != (a*b))
	    {
			cout << "No" << endl;
		}	
		else if(a%ans == 0 && b%ans == 0) cout << "Yes\n";
		else cout << "No" << endl;
	}
	
	return 0;
}
