#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int arr[100005],n;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	int coun = 0;
	
	for(int i = 2; i <= n; i++)
	{
		if(arr[i]!=arr[i-1]) coun++;		
	}
	
	cout << coun+1 << endl;
	
	return 0;
}
