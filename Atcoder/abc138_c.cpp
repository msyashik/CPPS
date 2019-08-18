#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1000005
int main()
{
	int n,arr[55];
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	sort(arr+1,arr+n+1);
	
	double sum = arr[1];
	
	for(int i = 2; i <= n; i++)
	{
		sum = (sum + arr[i]) / (2*1.0);
	}
	cout << setprecision(5) << fixed << sum << endl;
	
	return 0;
}
