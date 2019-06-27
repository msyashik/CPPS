//Problem Link : https://codeforces.com/problemset/problem/1183/A

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
    int n;
    
    cin >> n;
    
    for(int i = n; ;i++)
    {
		int ans = 0;
		
		int m = i;
		
		while(m)
		{
			ans += (m%10);
			
			m/=10;
		}
		
		//cout << i << endl;
	    	
		if(ans%4 == 0) {cout << i << endl;return 0;}
	}
    return 0;	
}
