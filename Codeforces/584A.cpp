#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int n, k;
	
	cin >> n >> k;
	
	if(k == 10 && n == 1) cout << -1 << endl;
	else if(k == 10)
	{
		int len = n-2;
		cout << k ;
		for(int i = 1; i <= len; i++)
		{
			cout << 0;
		}
	}
	else
	{
		int len = n-1;
		cout << k;
		for(int i = 1; i <= len; i++) cout << 0;
	}
	
	return 0;
}
