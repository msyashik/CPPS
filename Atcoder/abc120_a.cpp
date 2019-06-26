//Probelem Link: https://atcoder.jp/contests/abc120/tasks/abc120_a

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
    int a,b,c;
    
    cin >> a >> b >> c;
    
    
    if(a*c <= b) cout << c << endl;
    else cout << b/a << endl;
    
    return 0;	
}
