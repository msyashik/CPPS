#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int n,arr[110];
	
	cin >> n;
	
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	sort(arr, arr+n);
	
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
	return 0;
}
