#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int n, h,a;
	
	cin >> n >> h;
	
	int sum = 0;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		
		if(a > h) sum += 2;
		else sum += 1;
	}
	
	cout << sum <<  endl;

	return 0;
}
