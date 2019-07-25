#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int t,arr[100005];
	
	cin >> t;
	for(int i = 1; i<= t; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr+1, arr+t+1);
	
	int f = arr[1],l = arr[t];
	
	cout << abs(f-arr[2]) << " " << abs(f-l) << endl;
	
	for(int i = 2; i <= t-1; i++)
	{
		cout << min(abs(arr[i] - arr[i-1]), abs(arr[i] - arr[i+1])) << " ";
		cout << max(abs(arr[i] - f), abs(arr[i] - l)) << endl;
	}
	
	cout << abs(l-arr[t-1]) << " " << abs(l-f) << endl;
	
	
	return 0;
}
