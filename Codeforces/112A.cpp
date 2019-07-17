#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	
	string ch, bh;
	
	cin >> ch >> bh;
	
	transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
	transform(bh.begin(), bh.end(), bh.begin(), ::tolower);
	
	if(ch < bh) cout << -1 << endl;
	else if(ch > bh) cout << 1 << endl;
	else cout << 0 << endl;
	
	return 0;
}
