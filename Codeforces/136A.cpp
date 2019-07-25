#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int t,arr[105], brr[105];
	
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> arr[i];
		brr[arr[i]] = i;
	}
	
	for(int i = 1; i<= t; i++)
	{
		cout << brr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
