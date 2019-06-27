//Problem Link: https://atcoder.jp/contests/abc116/tasks/abc116_a

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
    Coming
     
    int a,b,c;
    
    cin >> a>> b >>c;
    
    int s = (a+b+c) / 2;
    
    
    int ans = sqrt(s*(s-a)*(s-b)*(s-c));
    
    cout << ans << endl;
    	
	return 0;
}
