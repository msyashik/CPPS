//Problem link : https://www.codechef.com/JUNE19B/problems/SUMAGCD

#include <bits/stdc++.h>
 
using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int main()
{
	Coming 
	
    ll t, n,arr[100005];
    
    cin >> t;
    
    while(t--)
    {
		cin >> n;
		
		for(int i = 1; i <= n; i++) cin >> arr[i];
		
		if(n == 2) {cout << arr[1]+arr[2] << endl;continue;}
		
		int mx1 = 0;
		
		for(int i = 1; i <= n; i++)
		{
			if(arr[i] >= mx1) mx1 = arr[i];
		} 
		
		int mx2 = 0;
		
		for(int i = 1; i <= n; i++)
		{
			if(arr[i] >= mx2 && arr[i] < mx1) mx2 = arr[i];
		}
		
		if(mx2 == 0) {cout << 2*mx1 << endl;continue;}
		
		ll gcd1 = 0, gcd2 = 0;
		
		for(int i = 1; i <= n; i++)
		{
			if(arr[i] != mx1)
			{
				gcd1 = __gcd(gcd1, arr[i]);
			}
		}
		
		gcd1+=mx1;
		
		for(int i = 1; i <= n; i++)
		{
			if(arr[i] != mx2)
			{
				gcd2 = __gcd(gcd2, arr[i]);
			}
		}
		
		gcd2+=mx2;
		
		cout << max(gcd1,gcd2) << endl; 
	}	
    	
	return 0;
	
}
