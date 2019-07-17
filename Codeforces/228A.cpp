#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int a, b, c,d;
	
	set<int>s;
	
	cin >> a >> b >> c >> d;
	
	s.insert(a);
	s.insert(b);
	s.insert(c);
	s.insert(d);
	
	cout << 4-s.size() << endl;
	
	return 0;
}
