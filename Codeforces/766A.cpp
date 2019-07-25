#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	string ch, bh;
	
	cin >> ch >> bh;
	if(ch == bh) cout << -1 << endl;
	else cout << max(ch.size(), bh.size()) << endl;
	
	return 0;
}
