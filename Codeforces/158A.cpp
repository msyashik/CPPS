#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int n,k,coun = 0, a[55];
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int ans = a[k];
	
	for(int i = 1; i<= n; i++)
	{
		if(a[i] >= ans && a[i] >= 1) coun++;
	}
	cout << coun << endl;
	
	return 0;
}
