#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
    ll a, b;
    
    cin >> a >> b;	
    
    if(a == b || (a+1 == b)) cout << -1 << endl;
    
    else if(a%2)
    {
		if(b-a == 2) cout << -1 << endl;
		else cout << a+1 << " " << a+2 << " " << a+3 << endl;
	}
	else
	{
		cout << a << " " << a+1 << " " << a+2 << endl;
	}
    
    
	return 0;
}
