#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	
	string ch,bh;
	
	cin >> ch >> bh;
	
	reverse(ch.begin(), ch.end());
	
	if(ch == bh) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
