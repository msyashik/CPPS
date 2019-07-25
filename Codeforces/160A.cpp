#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int t,arr[105],coun = 0, sum = 0, ans = 0;
	
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >>arr[i];
		sum += arr[i];
	}
	
	sort(arr, arr+t);
	
	for(int i = t-1; i >= 0; i--)
	{
		if(sum >= ans)
		{
			coun++;
			sum -= arr[i];
			ans += arr[i];
		}
		else break;
	}
	
	cout << coun << endl;
	
	return 0;
}
