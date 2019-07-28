#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
 
int main()
{
    ll a ,b;
    cin >> a >> b;
    ll mid = (a+b) / 2;
    ll ans1 = abs(a-mid);
    ll ans2 = abs(b-mid);
    if(ans1 == ans2) cout << mid << endl;
    else cout << "IMPOSSIBLE\n";
    return 0;
}
