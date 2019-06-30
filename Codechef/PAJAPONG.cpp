//Problem Link : https://www.codechef.com/LTIME73B/problems/PAJAPONG

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
    Coming 
    
    ll t, a, b,c;
    
    cin >> t;
    
    while(t--)
    {
		cin >> a >> b >> c;
		
		ll ans = (a+b) / c;
		
		ans++;
		
		if(ans%2 == 0) cout << "Paja\n";
		else cout << "Chef\n";
	}
     
	return 0;
}
