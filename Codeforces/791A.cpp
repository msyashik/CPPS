#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int a, b;
	
	cin >> a >> b;
	
	int sum = 0;
	
	while(a <= b)
	{
		 a *= 3;
		 b *= 2;
		 
		 sum++;
	}
	
	cout << sum << endl;
	
	return 0;
}
