//Problem Link : https://atcoder.jp/contests/abc131/tasks/abc131_c


#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
int main()
{
    ll a,b,c,d;
    
    cin >> a >> b >> c >> d;
    
    ll ans1 = (b/c) - (a/c);
    
    if(a%c == 0) ans1++;
    
    ll ans2 = (b/d) - (a/d);
    
    if(a%d == 0) ans2++;
    
    ll anss = (c*d) / (__gcd(c,d));
    
    ll ans3 = (b/(anss)) - (a / (anss));
    
    if(a%anss == 0) ans3++;
    
    ll sum = ans1 + ans2 - ans3;
    
    cout << (b-a+1) - sum << endl;
	return 0;
}
