#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int t, a, b, c;
	
	cin >> t;
	
	int sum = 0;
	
	while(t--)
	{
		int coun = 0;
		
		cin >> a>> b >> c;
		
		if(a == 1) coun++;
		if(b == 1) coun++;
		if(c == 1) coun++;
		
		if(coun >= 2) sum++;
	}
	
	cout << sum << endl;
	
	return 0;
	
}
