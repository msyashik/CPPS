//Problem link : https://www.codechef.com/JUNE19B/problems/RSIGNS

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define mod 1000000007

ll func(ll p, ll po)
{
	if(po == 0) return 1;
	else if(po%2 == 0)
	{
		ll ans = func(p, po/2);
		
		return ((ans%mod) * (ans%mod)) % mod;
	}
	else return ((p%mod) * (func(p, po-1)%mod))%mod;
}

int main()
{		
   Coming 	
  
   int t;
   ll k;
   
   cin >> t;
   
   while(t--)
   {
	   cin >> k;
	   
	   ll ans = ((func(2,k-1) % mod) * (10%mod)) % mod;   
       
       cout << ans << endl;
  
    }		
    return 0;
}
