#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
int main()
{
	ll x,y, a, b;
	
	while(scanf("%lld %lld", &a, &b) == 2)
	{
	    ll ans = gcdExtended(a,b,&x,&y);
	    
	    if(a == b)
	    {
			printf("%lld", min(x,y));
			printf(" %lld %lld\n", max(x,y), ans);
		}
	    else printf("%lld %lld %lld\n", x,y,ans);
	    
	}
	
	return 0;
}
